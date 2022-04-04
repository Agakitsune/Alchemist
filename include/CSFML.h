/*
** EPITECH PROJECT, 2022
** GameEngine
** File description:
** CSFML
*/

#ifndef CSFML_H_
    #define CSFML_H_

    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Graphics.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

    #define VECTOR2I(x, y)  (sfVector2i){x, y}
    #define VECTOR2U(x, y)  (sfVector2u){x, y}
    #define VECTOR2F(x, y)  (sfVector2f){x, y}

    #define IRECT(x, y, width, height)   (sfIntRect){x, y, width, height}
    #define FRECT(x, y, width, height)   (sfFloatRect){x, y, width, height}

    #define VECTOR_FACTOR(vector, factor)\
    (__typeof__(vector)){(vector).x * factor, (vector).y * factor}

    #define VECTOR_ADD(a, b)    (__typeof__(a)){(a).x + (b).x, (a).y + (b).y}
    #define VECTOR_SUB(a, b)    (__typeof__(a)){(a).x - (b).x, (a).y - (b).y}
    #define VECTOR_MUL(a, b)    (__typeof__(a)){(a).x * (b).x, (a).y * (b).y}
    #define VECTOR_DIV(a, b)\
    (__typeof__(a)){\
    (((b).x != 0) ? ((a).x / (b).x) : (0)),\
    (((b).y != 0) ? ((a).y / (b).y) : (0))}

    #define RECT_SIZE(rect)  VECTOR2F((rect).width, (rect).height)

#endif /* !CSFML_H_ */
