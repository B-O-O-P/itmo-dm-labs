
# Лабораторная работа по машине Тьюринга

## Задача A. Чётность числа нулей

Имя выходного файла: zero.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 0

Это ознакомительная задача. В ней нужно посчитать чётность числа нулей, записанных на ленте
и допустить строки с чётным числом нулей.
Например, это можно сделать с помощью такого кода:

```
start: s
accept: ac
reject: rj
blank: _
s _ -> ac _ ^
s 0 -> n _ >
n 0 -> s _ >
n _ -> rj _ >
```

В систему нужно посылать файл с соответствующим названием в условии. Символы и состояния — строки. Направления переходов — <,> или ^. Изначально головка стоит в начале входа. Всё
вне слова заполнено символом **blank**. Если попытаться пойти по правилу, которого нет в машине,
вы автоматически попадёте в отвергающее состояние.

### Формат входного файла

На ленте записано от одного до десяти нулей.

### Формат выходного файла

Машина должна перейти в допускающее состояние, если число нулей чётно, и в отвергающее
иначе.

### Примеры

**лента в начале**
```
0 
```

**лента в конце**
```
rejected
```

**лента в начале**
```
0 0
```

**лента в конце**
``` 
accepted
```

### [Решение](zero.out)

## Задача B. Сложение двух чисел

Имя выходного файла: aplusb.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте сложение двух чисел на одноленточной машине Тьюринга.

### Формат входного файла

На ленте через + записаны два числа _a_ и _b_ ( 0 ≤ _a_ ≤ 2^15 ) в двоичной системе счисления без
ведущих нулей.

### Формат выходного файла

В конце на ленте должна быть записана сумма чисел в том же формате, головка должна указывать на начало этого числа, помимо этого числа на ленте ничего не должно быть. Слово должно
быть допущено.

### Примеры

**лента в начале**
```
1 1 + 1 0
```

**лента в конце**
```
accepted
1 0 1
```

### [Решение](aplusb.out)

## Задача C. Зеркальное отображение

Имя выходного файла: mirror.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

На ленте записано слово _w_. Требуется найти слово _s_ = _ww′_, где _w′_ - слово _w_, записанное в
обратном порядке. Реализуйте алгоритм на одноленточной машине Тьюринга.

### Формат входного файла

На ленте записано слово _w_ (_w_ ∈ {0, 1}*, 1 ≤ |_w_| ≤ 200 ). Головка увазывает на первую букву
слова.

### Формат выходного файла

В конце на ленте должно быть записано слово _s_, головка должна указывать на начало этого
слова. На ленте ничего не должно быть. Слово должно быть допущено.

### Примеры

**лента в начале**
```
1 0 1 0 0
```

**лента в конце**
```
accepted
1 0 1 0 0 0 0 1 0 1
```

### [Решение](mirror.out)

## Задача D. Тандемный повтор

Имя выходного файла: tandem.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Проверьте является ли слово тандемным повтором на одноленточной машине Тьюринга.

### Формат входного файла

На ленте записано слово _s_ ( 1 ≤ |_s_| ≤ 100 ), состоящее из символов 0 и 1.

### Формат выходного файла

Машина Тьюринга должна завершаться в допускающем состоянии, если слово является танденмным повтором, и в отвергающем в противном случае.

### Примеры

**лента в начале**
```
1 1 0 1 1 0
```

**лента в конце**
```
accepted
```

### [Решение](tandem.out)

## Задача E. Сбалансированные скобки

Имя выходного файла: balanced.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте на машине Тьюринга проверку слова на принадлежность языку правильных скобочных последовательностей. Напомним, что правильной скобочной последовательностью называется
строка, удовлетворяющая грамматике _S_ = ε | (_S_)_S_.

### Формат входного файла

На ленте написана последовательность открывающих и закрывающих скобок. Её длина не превышает 100 символов.

### Формат выходного файла

После работы машина Тьюринга должна перейти в допускающее состояние, если исходное слово
принадлежит языку правильных скобочных последовательностей и в отвергающее состояние иначе.

### Примеры

**лента в начале**
```

```

**лента в конце**
```
accepted
```

**лента в начале**
```
)
```

**лента в конце**
```
rejected
```

**лента в начале**
```
( )
```
 
**лента в конце**
```
accepted
```

### [Решение](balanced.out)

## Задача F. Развернутое слово

Имя выходного файла: reverse.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

На ленте записано слово _w_. Требуется найти слово _s_ = _w′_, где _w′_ - слово _w_, записанное в обратном
порядке. Реализуйте алгоритм на одноленточной машине Тьюринга.

### Формат входного файла

На ленте записано слово _w_ (_w_ ∈ {0, 1}*, 1 ≤ |_w_| ≤ 200 ). Головка увазывает на первую букву
слова.

### Формат выходного файла

В конце на ленте должно быть записано слово _s_, головка должна указывать на начало этого
слова. На ленте ничего не должно быть. Слово должно быть допущено.

### Примеры

**лента в начале**
```
1 0 1 0 0 accepted
```

**лента в конце**
```
0 0 1 0 1
```

## Задача G. Сравнение двух чисел

Имя выходного файла: less.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте оператор меньше для двух чисел на одноленточной машине Тьюринга.

### Формат входного файла

На ленте через<записаны два числа _a_ и _b_ ( |_a_|, |_b_| ≤ 1000 ) в двоичной системе счисления без
ведущих нулей.

### Формат выходного файла

Машина должна перейти в допускающее состояние, если первое число меньше второго, и в от-
вергающее иначе.

### Примеры

**лента в начале**
```
1 1 < 1 0 
```

**лента в конце**
```
rejected
```

**лента в начале**
```
0 < 1 
```

**лента в конце**
```
accepted
```

### [Решение](less.out)

## Задача H. Из троичной в двоичную.

Имя выходного файла: convertto2.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

На ленте записано число _w_ в троичной системе счисления. Требуется перевести его в двоичную
систему счисления. Реализуйте алгоритм на одноленточной машине Тьюринга.

### Формат входного файла

На ленте записано число _w_ без ведущих нулей. ( 1 ≤ |_w_| ≤ 9 ). Головка увазывает на первую
цифру числа.

### Формат выходного файла

В конце на ленте должно быть записано число _s_, представляющее собой двоичную запись числа
_w_. Головка должна указывать на первую цифру числа _s_. Помимо этого числа на ленте ничего не
должно быть. Число должно быть допущено.

### Примеры

**лента в начале**
```
1 0 2
```

**лента в конце**
``` 
accepted
1 0 1 1
```

### [Решение](convertto2.out)

## Задача I. Умножение двух чисел

Имя выходного файла: multiplication.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте умножение двух чисел на одноленточной машине Тьюринга.

### Формат входного файла

На ленте через * записаны два числа _a_ и _b_( 10000 ≥ _a_ ≥ _b_ ≥ 0, _a_*_b_ ≤ 10000 ) в двоичной
системе счисления без ведущих нулей. Биты записаны от старшего к младшему. То есть числу 6
соответствует двоичное число 110.

### Формат выходного файла

В конце на ленте должно быть записано произведение чисел в том же формате, головка должна
указывать на начало этого числа, помимо этого числа на ленте ничего не должно быть. Слово
должно быть допущено.

### Примеры

**лента в начале**
```
1 1 * 1 0
```

** лента в конце**
```
accepted
1 1 0
```

### [Решение](multiplication.out)

## Задача J. Логические выражения в постфиксной записи

Имя выходного файла: postfixlogic.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте вычисление логических выражений, состоящих из констант, конъюнкций и дизъюнкций на многоленточной машине Тьюринга.

### Формат входного файла

На первой ленте записано логическое выражение в постфиксной (обратной польской) записи.

Значения символов следующие:

* 0 — ложь

* 1 — истина

* o — логическое "или"

* a — логическое "и"

Длина выражения не превышает 200 символов.

### Формат выходного файла

В конце работы головка первой ленты должна указывать на вычисленное значение логического
выражения.

### Примеры

**лента в начале**
```
1 0 a 1 o
```

**лента в конце**
```
accepted
1
```

**лента в начале**
```
0 1 o 0 o 1 a 0 a
```

**лента в конце**
```
accepted
0
```

### [Решение](postfixlogic.out)

## Задача K. Логические выражения в инфиксной записи

Имя выходного файла: infixlogic.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 1

Реализуйте вычисление логических выражений, состоящих из констант, конъюнкций и дизъюнкций на многоленточной машине Тьюринга.

### Формат входного файла

На первой ленте записано логическое выражение в инфиксной записи. Значения символов следующие:


* 0 — ложь

* 1 — истина

* o — логическое "или"

* a — логическое "и"

Кроме перечисленных символов на ленте могут присутствовать открывающие и закрывающие
скобки (**(** и **)**соответственно). Логическое "и" имеет больший приоритет, чем логическое "или".
Длина выражения не превышает 200 символов.

##№ Формат выходного файла

В конце работы головка первой ленты должна указывать на вычисленное значение логического
выражения.

##№ Примеры

**лента в начале**
```
1 a 0 o 1 
```

**лента в конце**
```
accepted
1
```

**лента в начале**
```
(0 o 0 o 1) a 1 a 0
```

**лента в конце**
```
accepted
0
```

### [Решение](infixlogic.out)

## Задача L. Вычисление факториала

Имя выходного файла: factorial.out

Ограничение по времени: 10 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 2

Реализуйте вычисление факториала двоичного числа на одноленточной машине Тьюринга

### Формат входного файла

На ленте через записано одно число _a_ ( 1 ≤ _a_ ≤ 30 ) в двоичной системе счисления без ведущих
нулей.

### Формат выходного файла

В конце на ленте должен быть записан факториал числа _a_ в том же формате, головка должна
указывать на начало этого числа, помимо этого числа на ленте ничего не должно быть. Слово
должно быть допущено.

### Примеры

**лента в начале**
```
1 0 1 
```

**лента в конце**
```
accepted
1 1 1 1 0 0 0
```

### [Решение](factorial.out)

## Задача M. Сортировка

Имя выходного файла: sorting.out

Ограничение по времени: 100 000 000 шагов

Максимальное число состояний: 500

Баллы за задачу: 2

Реализуйте сортировку набора чисел на многоленточной машине Тьюринга.

### Формат входного файла

На первой ленте через символ «|» записаны _n_ чисел ( 1 ≤ _n_ ≤ 20 ) a_i в двоичной системе счисления
без ведущих нулей, старшие биты — слева ( 0 ≤ a_i < 1024 ).
Само число _n_ на ленте не записано.

### Формат выходного файла

В результате вычислений на первой ленте должны быть записаны те же _n_ чисел в таком же
формате, в порядке неубывания. Головка первой ленты должна указывать на начало первого числа,
кроме чисел и разделителей, на ленте ничего не должно быть. Слово должно быть допущено.

### Примеры

**лента в начале**
```
1 1 0 | 1 1 | 1 0 1
```

**лента в конце**
``` 
accepted
1 1 | 1 0 1 | 1 1 0
```

### [Решение](sorting.out)

