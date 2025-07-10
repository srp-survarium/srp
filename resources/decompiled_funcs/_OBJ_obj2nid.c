int __cdecl OBJ_obj2nid(const asn1_object_st *a)
{
  int v1; // edi
  int result; // eax
  void **v3; // eax
  int v4; // ebx
  int v5; // esi
  const unsigned int *v6; // ebp
  signed int v7; // eax
  _DWORD data[2]; // [esp+4h] [ebp-8h] BYREF

  v1 = 0;
  if ( !a )
    return 0;
  result = a->nid;
  if ( !result )
  {
    if ( added && (data[1] = a, data[0] = 0, (v3 = lh_retrieve((lhash_st *)added, data)) != 0) )
    {
      return *((_DWORD *)v3[1] + 2);
    }
    else
    {
      v4 = 840;
      do
      {
        v5 = (v4 + v1) / 2;
        v6 = &obj_objs[v5];
        v7 = obj_cmp(&a);
        if ( v7 >= 0 )
        {
          if ( v7 <= 0 )
            break;
          v1 = v5 + 1;
        }
        else
        {
          v4 = (v4 + v1) / 2;
        }
      }
      while ( v1 < v4 );
      if ( !v7 && v6 )
        return nid_objs[*v6].nid;
      else
        return 0;
    }
  }
  return result;
}
