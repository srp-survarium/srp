void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}
