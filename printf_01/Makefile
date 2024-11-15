NAME = libftprintf.a
SRC = ft_printf.c ft_putword.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

# ライブラリの生成
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# オブジェクトファイルの生成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# デフォルトターゲット
all: $(NAME)

# テスト用の実行ファイル
test_program: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test_program

# クリーンアップ
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re
