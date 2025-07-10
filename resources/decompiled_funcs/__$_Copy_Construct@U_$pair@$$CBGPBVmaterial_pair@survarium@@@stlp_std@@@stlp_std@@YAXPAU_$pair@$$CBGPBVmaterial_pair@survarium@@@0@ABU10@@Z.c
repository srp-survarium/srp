void __cdecl stlp_std::_Copy_Construct<stlp_std::pair<unsigned short const,survarium::material_pair const *>>(
        stlp_std::pair<unsigned short const ,survarium::material_pair const *> *__p,
        const stlp_std::pair<unsigned short const ,survarium::material_pair const *> *__val)
{
  _DWORD *v2; // [esp+4h] [ebp-8h]

  v2 = operator new(8u, __p);
  if ( v2 )
  {
    *(_WORD *)v2 = __val->first;
    v2[1] = __val->second;
  }
}
