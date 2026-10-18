#include "calculator.h"
#include "mtest.h"

/* På grund af muligheden for afrundingsfejl ved floating-point tal, angiver vi en delta,
 * som er en lille tilladt afvigelse, når vi sammenligner den faktiske og forventede værdi. */
const double delta = 0.000001;

/* Her er et eksempel på hvordan man kan skrive en unit test af funktionen `do_next_op`. */
TEST_CASE(do_next_op_case0, {
    /* Arrange */
    double akkumulator = 2.0;
    /* Act */
    do_next_op('+', 3.0, &akkumulator);
    /* Assert */
    CHECK_EQ_DOUBLE(akkumulator, 5.0, delta);
})

/*************************************************
 * Skriv dine egne unit test af 'do_next_op', så *
 * du tester forskellige operatorer og operander.*
 *************************************************/

// Test af division med nul
TEST_CASE(do_next_op_case1, {
    double akkumulator = 10.0;

    do_next_op('/', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 10.0, delta);
})

// Test af kvadratrod af negativt tal
TEST_CASE(do_next_op_case2, {
    double akkumulator = -9.0;

    do_next_op('#', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, -9.0, delta);
})

// Test af multiplikation
TEST_CASE(do_next_op_case3, {
    double akkumulator = 5.0;

    do_next_op('*', 3.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 15.0, delta);
})

// Test af division
TEST_CASE(do_next_op_case4, {
    double akkumulator = 12.0;

    do_next_op('/', 4.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 3.0, delta);
})

// Test af potens
TEST_CASE(do_next_op_case5, {
    double akkumulator = 2.0;

    do_next_op('^', 3.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 8.0, delta);
})

// Test af fortegnsskift
TEST_CASE(do_next_op_case6, {
    double akkumulator = 7.0;

    do_next_op('%', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, -7.0, delta);
})

// Test af reciprok værdi
TEST_CASE(do_next_op_case7, {
    double akkumulator = 4.0;

    do_next_op('!', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 0.25, delta);
})

// Test af reciprok værdi af nul
TEST_CASE(do_next_op_case8, {
    double akkumulator = 0.0;

    do_next_op('!', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 0.0, delta);
})

// Test af subtraktion
TEST_CASE(do_next_op_case9, {
    double akkumulator = 10.0;

    do_next_op('-', 4.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 6.0, delta);
})

// Test af kvadratrod af positivt tal
TEST_CASE(do_next_op_case10, {
    double akkumulator = 9.0;

    do_next_op('#', 0.0, &akkumulator);

    CHECK_EQ_DOUBLE(akkumulator, 3.0, delta);
})

/* Her har underviseren implementeret regne-eksemplet fra opgavebeskrivelsen */
TEST_CASE(do_next_op_example_sequence, {
    double akkumulator = 0.0;
    do_next_op('+', 5.0, &akkumulator);             /* Enter operator, and an optional operand: + 5.000000 */
    CHECK_EQ_DOUBLE(akkumulator, 5.0, delta);       /* Result so far is 5.000000. */

    do_next_op('-', 6.0, &akkumulator);             /* Enter operator, and an optional operand: - 6.000000 */
    CHECK_EQ_DOUBLE(akkumulator, -1.0, delta);      /* Result so far is -1.000000. */

    do_next_op('*', 3.0, &akkumulator);             /* Enter operator, and an optional operand: * 3.000000 */
    CHECK_EQ_DOUBLE(akkumulator, -3.0, delta);      /* Result so far is -3.000000. */

    do_next_op('#', 0.0, &akkumulator);             /* Enter operator, and an optional operand: # */
    CHECK_EQ_DOUBLE(akkumulator, -3.0, delta);      /* Result so far is -3.000000. */

    do_next_op('%', 0.0, &akkumulator);             /* Enter operator, and an optional operand: % */
    CHECK_EQ_DOUBLE(akkumulator, 3.0, delta);       /* Result so far is 3.000000. */

    do_next_op('#', 0.0, &akkumulator);             /* Enter operator, and an optional operand: # */
    CHECK_EQ_DOUBLE(akkumulator, 1.732051, delta);  /* Result so far is 1.732051. */

    do_next_op('^', 2.0, &akkumulator);             /* Enter operator, and an optional operand: ^ 2.000000 */
    CHECK_EQ_DOUBLE(akkumulator, 3.0, delta);       /* Result so far is 3.000000. */

    do_next_op('*', 4.0, &akkumulator);             /* Enter operator, and an optional operand: * 4.000000 */
    CHECK_EQ_DOUBLE(akkumulator, 12.0, delta);      /* Result so far is 12.000000. */

    do_next_op('!', 0.0, &akkumulator);             /* Enter operator, and an optional operand: ! */
    CHECK_EQ_DOUBLE(akkumulator, 0.083333, delta);  /* Result so far is 0.083333. */
})

/* Register your test cases to this macro: */
MAIN_RUN_TESTS(
    do_next_op_case0,
    do_next_op_case1,
    do_next_op_case2,
    do_next_op_case3,
    do_next_op_case4,
    do_next_op_case5,
    do_next_op_case6,
    do_next_op_case7,
    do_next_op_case8,
    do_next_op_case9,
    do_next_op_case10,
    do_next_op_example_sequence
)
