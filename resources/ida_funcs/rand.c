unsigned int __cdecl rand()
{
  _tiddata *v0; // eax
  unsigned int v1; // ecx

  v0 = _getptd();
  v1 = (unsigned int)&loc_269EC3 + 214013 * v0->_holdrand;
  v0->_holdrand = v1;
  return HIWORD(v1) & 0x7FFF;
}
