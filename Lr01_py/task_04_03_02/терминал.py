# Программирование на языке высокого уровня (Python).
# Задание №4.3.2
#
# Выполнил: Иванов Даниил Евгеньевич
# Группа: ПИН-б-о-22-1
# E-mail: daniilivanov752@gmail.com

from пицца import *
from заказ import *


class Терминал:
    """Класс Терминал обеспечивает взаимодействие с клиентом."""

    КОМПАНИЯ = 'PizzaHub'
    КОМАНДА_ОТМЕНА_ЗАКАЗА = -1
    КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА = 0
    ВЕРСИЯ = 1.0

    def __init__(self):
        """Конструктор класса.

        self.меню: список доступных пицц;
        self.заказ: список заказанных пицц;
        self.отображать_меню: определяет отображение меню
                              равен True: при создании терминала,
                              после отмены или подтверждения заказа.
        """
        # Доступные пиццы
        self.меню = [ПиццаПепперони(), ПиццаБарбекю(), ПиццаДарыМоря()]
        self.заказ = None
        self.отображать_меню = True

    def __str__(self):
        """Вернуть строковое представление класса.

        Формат вывода:

        Имя пиццерии, версия программы.
        """
        return f'{Терминал.КОМПАНИЯ}, {Терминал.ВЕРСИЯ}'

    def показать_меню(self):
        """Показать меню.

        Показать меню следует только при наличии флага self.отображать_меню
        self.отображать_меню устанавливается в False после вывода меню.

        Формат вывода:

        Пиццерия #1
        Добро пожаловать!

        Меню:
        1. Пицца: Пепперони | Цена: 350.00 р.
           Тесто: тонкое Соус: томатный
           Начинка: пепперони, сыр моцарелла
        2. Пицца: Барбекю | Цена: 450.00 р.
           Тесто: тонкое Соус: барбекю
           Начинка: бекон, ветчина, зелень, сыр моцарелла
        3. Пицца: Дары моря | Цена: 550.00 р.
           Тесто: пышное Соус: тар-тар
           Начинка: кальмары, креветки, мидии, сыр моцарелла
        Для выбора укажите цифру через <ENTER>.
        Для отмены заказа введите -1
        Для подтверждения заказа введите 0
        """
        if not self.отображать_меню:
            return

        print(
            f'{Терминал.КОМПАНИЯ}', 'Добро пожаловать!', '', 'Меню:',
            *[f'{i + 1}. ' + str(pizza) for i, pizza in enumerate(self.меню)],
            'Для выбора укажите цифру через <ENTER>.',
            'Для отмены заказа введите -1',
            'Для подтверждения заказа введите 0',
            sep='\n'
        )

        self.отображать_меню = False

    def обработать_команду(self, пункт_меню):
        """Обработать действие пользователя.

        Аргументы:
          - пункт_меню (str): выбор пользователя.

        Возможные значения "пункт_меню":
          - -1: отменить заказ;
          -  0: подтвердить заказ; при этом осуществляется
                выставление счета, оплата, а также выполняется заказ;
                после заказ удаляется (= None)
          - 1..len(self.меню): добавление пиццы к добавить_к_заказу;
                               если заказ не создан, его нужно создать.
          - иначе: сообщить о невозможности обработать команду.

        Каждое действие подтверждается выводом на экран, например:
        1
        Пицца Пепперони добавлена!
        2
        Пицца Барбекю добавлена!
        0
        Заказ подтвержен.
        """

        try:
            пункт_меню = int(пункт_меню)
            if пункт_меню == Терминал.КОМАНДА_ОТМЕНА_ЗАКАЗА:
                self.заказ = None
                print('Ваш заказ отменён')
            elif пункт_меню == Терминал.КОМАНДА_ПОДТВЕРЖДЕНИЕ_ЗАКАЗА:
                if self.заказ is not None:
                    print('Заказ подтвержен.')
                    print(self.заказ)
                    self.принять_оплату()
                    self.заказ.выполнить()
                # Проверьте, что подтверждение вызывается для созданного заказа
                # При возникновении ошибки необходимо вызвать команду
                # отмены заказа
            elif 1 <= пункт_меню <= len(self.меню):
                if self.заказ is None:
                    self.заказ = Заказ()
                self.заказ.добавить(self.меню[пункт_меню - 1])
                print(f'Пицца {self.заказ.заказанные_пиццы[-1].название} добавлена!')
                # Если заказ не создан, его нужно предварительно создать
            else:
                # За границей меню передаем управление в обработку исключений
                raise ValueError
        except ValueError:
            print("Не могу распознать команду! Проверьте ввод.")
        except Exception as e:
            print("Во время работы терминала произошла ошибка...", e)

    def рассчитать_сдачу(self, оплата):
        """Вернуть сдачу для 'оплата'.

        Если оплата меньше стоимости заказа, возбудить исключение ValueError.
        """
        if оплата < self.заказ.сумма():
            raise ValueError

        return оплата - self.заказ.сумма()

    def принять_оплату(self):
        """Обработать оплату.

        Эмулирует оплату заказа (клиент вводит сумму с клавиатуры).

        Если сумма оплаты недостаточна (определяет метод рассчитать_сдачу())
        или возникает другая ошибка - исключние передается выше.
        """
        try:
            print(f'Сумма заказа: {self.заказ.сумма():.2f}')
            оплата = float(input('Введите сумму: '))
            сдача = self.рассчитать_сдачу(оплата)
            print(f'Вы внесли {оплата:.2f} р. Сдача: {сдача:.2f} р.')
        except Exception:
            print("Оплата не удалась. Заказ будет отменен.")
            raise