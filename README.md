### VerLang docs (v1.1)

#### Tokens
- `TOKEN_INT` - целое число. В перспективе `BigInteger`, в коде `int`
- `TOKEN_PLUS` - символ `+`
- `TOKEN_MINUS` - символ `-`
- `TOKEN_FUCK` - оператор `fuck`
- `TOKEN_UNKNOWN` - токен неизвестного типа, на этапе лексера выдает исключение `_UnknownToken`, на этапе парсера `_ForbiddenToken`
- `TOKEN_TYPE_COUNT` - пустой токен для подсчета общего кол-ва токенов. Ведет себя аналогично `TOKEN_UNKNOWN`

#### Exceptions
- `_Ok (0)` - успешное выполнение программы
- `_InputFail (1)` - ошибка на этапе ввода программы
- `_UnknownToken (2)` - неизвестный токен на этапе лексера
- `_ForbiddenToken (3)` - запрещенный Женевской конвенцией на данном этапе токен
- `_ExceptionsCount (4)` - для подсчета кол-ва исключений

