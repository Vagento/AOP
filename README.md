# PHP AOP Extension
Aspect-Oriented Programming for PHP

## Introduction
Aspect-Oriented Programming (AOP) is a software development technique that allows for the addition of code to a 
program at runtime.


## Installation
TODO


## Terminology
* **Advice**: Additional behavior that can be added to a class or method, without modifying the original code.
* **Pointcut**: A method that can be used to determine if an aspect should be applied to a class or method, in our case,
  we use a string that matches the method name.
* **Aspect**: The callback/function that contains the additional behavior.
* **Joinpoint**: A point in the code where an aspect is applied.


## Roadmap:

<details>
<summary>Click to see the roadmap!</summary>

### Advices:
- [ ] Around
- [ ] Before
- [ ] After
- [ ] After Returning
- [ ] After Throwing

### Global functions (or static Interceptor methods):
- [ ] Should return an "Interceptor" class instance
  - [ ] `add_around(string $pointcut, Callable $aspect) {}`
  - [ ] `add_before(string $pointcut, Callable $aspect) {}`
  - [ ] `add_after(string $pointcut, Callable $aspect) {}`
  - [ ] `add_after_returning(string $pointcut, Callable $aspect) {}`
  - [ ] `add_after_throwing(string $pointcut, Callable $aspect) {}`
- [ ] Should return an "Override" class instance
  - [ ] `add_override(string $pointcut, mixed<string|object> $override) {}`
- [ ] Utils
  - [ ] `get_interceptors_by_pointcut(string $pointcut): array<Interceptor>`
  - [ ] `get_interceptors_by_name(string $name): array<Interceptor>`
  - [ ] `get_interceptor_by_name(string $name): array<Interceptor>`
  - [ ] `get_overrides_by_pointcut(string $pointcut): array<Override>`
  - [ ] `get_overrides_by_name(string $name): array<Override>`
  - [ ] `get_all_interceptors(): array<Interceptor>`
  - [ ] `get_all_overrides(): array<Override>`
  - [ ] `disable_interceptors_by_pointcut(string $pointcut)`
  - [ ] `disable_interceptors_by_name(string $name)`
  - [ ] `disable_overrides_by_pointcut(string $pointcut)`
  - [ ] `disable_overrides_by_name(string $name)`
  - [ ] `disable_all_interceptors()`
  - [ ] `disable_all_overrides()`
  - [ ] `remove_interceptors_by_pointcut(string $pointcut): int<number of removed interceptors>`
  - [ ] `remove_interceptors_by_name(string $pointcut): int<number of removed interceptors>`
  - [ ] `remove_overrides_by_pointcut(string $pointcut): int<number of removed overrides>`
  - [ ] `remove_overrides_by_name(string $pointcut): int<number of removed overrides>`
  
### PHP Classes:
- [ ] **JoinPoint (Class)**
  - [ ] `getArguments(): ?array {}`
  - [ ] `setArguments(array $arguments) {}`
  - [ ] `getException(): ?\Exception {}`
  - [ ] `getPointcut(): string {}`
  - [ ] `process(): ?mixed {}`
  - [ ] `execute(): ?mixed {}` same as process()
  - [ ] `getKindOfAdvice(): int {}`
  - [ ] `getObject(): ?object {}`
  - [ ] `getClass(): ?object {}` same as getObject()
  - [ ] `&getReturnedValue(): ?mixed {}`
  - [ ] `setReturnedValue(mixed $value) {}`
  - [ ] `getClassName(): ?string {}`
  - [ ] `getMethodName(): ?string {}`
  - [ ] `getFunctionName(): ?string {}`
  - [ ] `&getAssignedValue(): mixed {}` Only for properties
  - [ ] `setAssignedValue(mixed $value) {}` Only for properties
  - [ ] `getPropertyName(): ?string {}` Only for properties
  - [ ] `getPropertyValue(): ?mixed {}` Only for properties
  - [ ] `getName(): ?string {}`

- [ ] **Interceptor (Class)**
  - [ ] **Properties:**
    - [ ] `$pointcut`
    - [ ] `$kindOfAdvice`
    - [ ] `$enabled`
    - [ ] `$sortOrder`
    - [ ] `$name`
  - [ ] **Methods:**
    - [ ] `enable()`
    - [ ] `disable()`
    - [ ] `isEnabled(): bool`
    - [ ] `isDisabled(). bool`
    - [ ] `setSortOrder(int $sortOrder)`
    - [ ] `getSortOrder(): int`
    - [ ] `getPointcut(): string`
    - [ ] `getName(): string`
  - [ ] **Settings as arguments / array**
    - [ ] Sort order | int | default: 10
    - [ ] Enabled / Disabled | bool | default: true
    - [ ] Name | string | default: null

- [ ] **KindOfAdvice**
  - [ ] `const AROUND = 1`
  - [ ] `const BEFORE = 2`
  - [ ] `const AFTER = 4`
  - [ ] `const READ = 8`
  - [ ] `const WRITE = 16`
  - [ ] `const PROPERTY = 32`
  - [ ] `const METHOD = 64`
  - [ ] `const FUNCTION = 128`
  - [ ] `const RETURN = 256`
  - [ ] `const THROW = 512`
  - [ ] \+ Combination of constants (bitwise operations)

- [ ] **Override (Class)** (Override a class with another, which then can extend the original class)
  - [ ] **Properties:**
    - [ ] `$pointcut`
    - [ ] `$enabled`
    - [ ] `$sortOrder`
    - [ ] `$name`

- [ ] **Extension (Class)** (Extend a target -any target- with additional functionality 
      [@see Dart](https://dart.dev/guides/language/extension-methods))

</details>

