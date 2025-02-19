# Система Авторизации и Регистрации

Разработайте систему авторизации и регистрации с использованием языка программирования C++.

### Общее описание

Вам необходимо реализовать систему, которая позволит пользователям:

1. Регистрироваться в системе с указанием имени пользователя и пароля.

2. Авторизоваться с использованием имени пользователя и пароля.

3. Обеспечивать безопасность хранения паролей.

### Обязательные классы

**User** - класс, представляющий пользователя приложения.

**UserManager** - класс, ответственный за создание пользователей, хранение и проверку данных.

### Обязательные критерии

1. **Использование ООП:**

    * Разработка должна быть объектно-ориентированной.

    * Процедурный стиль недопустим.

2. **Принципы проектирования:**

    * Следовать принципу DRY (Don't Repeat Yourself).

    * Соблюдать принцип единственной ответственности (Single Responsibility Principle).

3. **Читаемость кода:**

    * Названия переменных, функций и классов должны быть осмысленными.

    * Использование бессмысленных имен (например, "a", "b", "temp", "something") недопустимо.

4. **Безопасность хранения паролей:**

    * Пароль должен храниться в защищённом виде (например, использовать хеширование).

    * Хранение пароля в открытом виде запрещено.

### Дополнительные требования

1. **Регистрация пользователя:**

    * Проверять, что имя пользователя уникально.

    * Сохранять данные о пользователях в памяти.

2. **Авторизация пользователя:**

    * Проверять введённый пароль на соответствие хешу сохранённого пароля.

3. **Обработка ошибок:**

    * Обрабатывать случаи, когда пользователь уже существует.

    * Обрабатывать ситуацию, когда вводится неверный пароль.

### Опционально:

* Реализовать возможность хранения пользователей в файле или базе данных.

* Добавить возможность смены пароля.

* Написать тесты для проверки функционала.


# Пример использования

``` c++
// Подключение к базе данных
Database db("postgres", "postgres", "123456", "127.0.0.1", "5432");

// Инициализация менеджера пользователей
UserManager userManager(db);
// Создание таблицы юзера в базе данных
userManager.createTable();

// Создание пользователя
userManager.createUser("user1", "user1@gmail.com", "123456");

// Чтение пользователя из базы данных и вывод его данных 
User user = userManager.getUserByUsername("user1");
user.print();
```