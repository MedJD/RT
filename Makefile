NAME = rt

SRCS = ft_add_light.c\
	   ft_add_object.c\
	   ft_angles.c\
	   ft_antialiasing.c\
	   ft_clamp.c\
	   ft_close.c\
	   ft_color.c\
	   ft_cube_ijk.c\
	   ft_cubic.c\
	   ft_detect_set_val.c\
	   ft_diffuse.c\
	   ft_draw.c\
	   ft_events_1.c\
	   ft_events_2.c\
	   ft_events_3.c\
	   ft_events_4.c\
	   ft_filter.c\
	   ft_filter_c.c\
	   ft_filter_mb.c\
	   ft_filter_mb1.c\
	   ft_fix_rec.c\
	   ft_fractals.c\
	   ft_get_data.c\
	   ft_hit.c\
	   ft_hit_cone.c\
	   ft_hit_cube_triangle.c\
	   ft_hit_cylinder.c\
	   ft_hit_disk.c\
	   ft_hit_hyperboloid.c\
	   ft_hit_moebius.c\
	   ft_hit_paraboloid.c\
	   ft_hit_perforated_cube.c\
	   ft_hit_plane.c\
	   ft_hit_sphere.c\
	   ft_hit_torus.c\
	   ft_init.c\
	   ft_lighting.c\
	   ft_lighting_help.c\
	   ft_loading.c\
	   ft_mlx_putpixel.c\
	   ft_noise_1.c\
	   ft_noise_2.c\
	   ft_parser.c\
	   ft_parser2.c\
	   ft_perlin.c\
	   ft_perlin_init.c\
	   ft_plane_mapping.c\
	   ft_process.c\
	   ft_process2.c\
	   ft_process_init.c\
	   ft_quadric.c\
	   ft_quartic.c\
	   ft_rand.c\
	   ft_ray.c\
	   ft_rotate.c\
	   ft_save_img.c\
	   ft_save_video.c\
	   ft_shading.c\
	   ft_specular.c\
	   ft_texture.c\
	   ft_ui_1.c\
	   ft_ui_2.c\
	   ft_vec_col.c\
	   ft_vector1.c\
	   ft_vector2.c\
	   ft_vector3.c\
	   ft_vects_ijk_1.c\
	   ft_vects_ijk_2.c\
	   ft_voronoi.c\
	   ft_voronoi_linear.c\
	   main.c

SRC = $(add prefix srcs/, $(SRCS))
SRCS_NORM = $(SRCS)

HEADERS = rt.h rt_struct.h rt_define.h
HEADER = headers
HEADERS_NORM = $(HEADERS)

LIBFT_NORM = $(shell find libft/ | grep '\.c' | cut -c 8-)
LIBFT_NORM += libft.h

OBJS_DIR = objs
OBJ = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OK_COLOR=\x1b[102;01m
GREEN_COLOR=\x1b[32;01m
YELLOW_COLOR=\x1b[33;01m
NO_COLOR=\x1b[0m
ERROR_COLOR=\x1b[101;01m
WARN_COLOR=\x1b[33;01m
BUILD_PRINT = $(GREEN_COLOR)rt successfully compiles$(NO_COLOR)
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
KO_STRING=$(ERROR_COLOR)[KO]$(NO_COLOR)
MLX_DIR = minilibx_macos
WIDTH = 1000

ifeq ($(shell uname), Darwin)
$(info MacOs detected)
MLX = -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
$(info $(shell uname) detected)
MLX = -lm -lmlx -lXext -lX11
endif

ifeq ($(shell uname), Darwin)
SDL2 = ./frameworks/SDL2.framework/Versions/A/SDL2
SDL2_IMAGE = ./frameworks/SDL2_image.framework/Versions/A/SDL2_image
SDL2_TTF = ./frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf
SDL2_MIXER = ./frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer
SDL_FLAGS = -I headers/SDL2 -F ./frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_MIXER 
else
SDL_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm
endif

ifeq ($(shell test $(WIDTH) -lt 1000; echo $$?), 0)
override WIDTH = 1000
endif

ifeq ($(shell test $(WIDTH) -gt 3000; echo $$?), 0)
override WIDTH = 3000
endif

CFLAGS = -D WIDTH=$(WIDTH) -Wall -Wextra -Werror
LIBFT = ./libft/ -lft
THREAD = -lpthread
MYFLAG =  $(MLX) -L $(LIBFT) $(THREAD)
MYFLAG += $(SDL_FLAGS)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJ)
	@make libmlx.a -C $(MLX_DIR)
	@make libft.a -C libft
	@gcc $(CFLAGS) -o $(NAME) $(filter-out $<, $+) $(MYFLAG)
	@echo "$(BUILD_PRINT)"

ifeq ($(shell uname), Darwin)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 $(SDL2) $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image $(SDL2_IMAGE) $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf $(SDL2_TTF) $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer $(SDL2_MIXER) $(NAME)
endif

$(OBJS_DIR):
	@mkdir -p $@

COMPILE_OBJECT = gcc -I headers/SDL2 -I ./minilibx_macos -I headers $(CFLAGS) -o $@ -c $< && echo "$(OK_STRING)" || echo "$(KO_STRING)"

objs/%.o: srcs/%.c headers/rt.h headers/rt_define.h headers/rt_struct.h
	@echo "Compiling $(W_COLOR)$<$(NO_COLOR) ==> $@ `$(COMPILE_OBJECT)`"

clean:
	@rm -f $(OBJ) && echo "$(YELLOW_COLOR)Deleting objects...$(NO_COLOR)"
	@make clean -C $(MLX_DIR)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME) && echo "$(YELLOW_COLOR)Deleting $(NAME)...$(NO_COLOR)"
	@make fclean -C libft

re: fclean all

norm: $(SRCS_NORM) $(HEADERS_NORM) $(LIBFT_NORM)

NORM = norminette $< | awk 'BEGIN{i = 0}{if ($$1 != "Norme:") i++}END{if (i == 0) print "$(OK_STRING)"; else print "$(KO_STRING)"}'

$(SRCS_NORM) : % : srcs/%
	@echo "check norminette $< ==> `$(NORM)`"

$(HEADERS_NORM) : % : headers/%
	@echo "check norminette $< ==> `$(NORM)`"

$(LIBFT_NORM) : % : libft/%
	@echo "check norminette $< ==> `$(NORM)`"

.PHONY: all, clean, fclean, re, norm
