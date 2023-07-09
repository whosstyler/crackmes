#include <iostream>

//https://crackmes.one/crackme/649edc7b33c5d460c17f1f08

int __cdecl auth( int* key, int multiValue ) {
    unsigned int i;
    int generatedKey{};
    for ( i = 0; i <= 7; ++i ) {
        if ( key[ i ] == 0 ) {
            std::cout << "Not divisible by 0, SKIPPED.\n";
            continue;
        }
        generatedKey += 799 * ( ( multiValue + 13087 ) / key[ i ] + 84675 ) + multiValue;
    }
    return generatedKey;
}

int* __cdecl codes( const char* word )
{
    int* code; // [rsp+20h] [rbp-10h]
    int i; // [rsp+28h] [rbp-8h]
    int length; // [rsp+2Ch] [rbp-4h]

    for ( length = 0; word[ length ]; ++length )
        ;
    code = ( int* )malloc( 4i64 * length );
    for ( i = 0; i < length; ++i )
        code[ i ] = word[ i ];
    return code;
}

// Function to generate all possible strings of length k
void generateStrings( std::string prefix, int k ) {
    if ( k == 0 ) {
        int* converted = codes( prefix.c_str( ) );
        if ( auth( converted, 5 ) % 5 == 3 )
            std::cout << "Workable string: " << prefix << std::endl;
        free( converted );
        return;
    }

    for ( char c = 'a'; c <= 'z'; ++c ) {
        std::string newPrefix = prefix + c;
        generateStrings( newPrefix, k - 1 );
    }
}

int main()
{
    int* converted; // [rsp+28h] [rbp-18h]
    converted = codes( "jqnh" );
    // basically if the auth function returns a value that is divisible by 5 and has a remainder of 3, then the key is correct
    if ( auth( converted, 5 ) % 5 == 3 )
        printf( "Correct key!" );
    else
        printf( "Incorrect Key!" );
}

