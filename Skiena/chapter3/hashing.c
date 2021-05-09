
// hashing algorithm -> get any type of structure (string, etc)
// and represent them as a single number
// -> Has to be spread out to reduce the chance of being duplicates
// -> Makes comparison between structs faster because int comparisons r constant

// djb2
unsigned long hash_djb2(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

// sdbm  -> very good distribution of hash keys
// static
unsigned long hash_sdbm(unsigned char* str)
{
    unsigned long hash = 0;
    int c;

    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}

// lose lose
// Really bad example of hashing algorithm
unsigned long hash_lose_lose(unsigned char *str)
{
    unsigned int hash = 0;
    int c;

    while ((c = *str++))
        hash += c;

    return hash;
}
