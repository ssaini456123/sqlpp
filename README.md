# Sqlpp

The cursed C Preprocessor for your SQL Files.


Goal:

```sql
--define k  TEST
--define 👅 BIGINT
--define 💫 PRIMARY KEY

CREATE TABLE IF NOT EXISTS k (
  id 👅 💫
)

```

its expansion using sqlpp would result in:

```sql

CREATE TABLE IF NOT EXISTS TEST (
  id BIGINT PIMRARY KEY
)
```

Checklist:

[ ] macro definitions
[ ] include directive
[ ] conditional compilation directives (--if,--endif,--ifdef, etc...)
