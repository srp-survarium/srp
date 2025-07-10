__int64 __thiscall SpeedTree::CGrass::RemoveInactiveCells(_DWORD *this, int a2)
{
  __int64 result; // rax
  int v3; // eax
  int v4; // [esp-8h] [ebp-84h] BYREF
  int *v5; // [esp+0h] [ebp-7Ch]
  int v6; // [esp+4h] [ebp-78h]
  int v7; // [esp+8h] [ebp-74h]
  int v8; // [esp+Ch] [ebp-70h]
  int v9; // [esp+10h] [ebp-6Ch]
  _DWORD *v10; // [esp+14h] [ebp-68h]
  int *v11; // [esp+1Ch] [ebp-60h]
  int v12; // [esp+20h] [ebp-5Ch]
  int v13; // [esp+24h] [ebp-58h]
  int v14; // [esp+44h] [ebp-38h]
  int v15; // [esp+48h] [ebp-34h]
  char v16[12]; // [esp+58h] [ebp-24h] BYREF
  _DWORD v17[4]; // [esp+64h] [ebp-18h] BYREF
  int v18; // [esp+74h] [ebp-8h] BYREF
  int v19; // [esp+78h] [ebp-4h]

  v10 = this;
  if ( (unsigned __int8)SpeedTree::CArray<void *,1>::reserve(0) )
    *(_DWORD *)(a2 + 8) = 0;
  else
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 12);
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::begin(&v18);
  while ( 1 )
  {
    v17[1] = 0;
    v17[2] = 0;
    LODWORD(result) = v18;
    HIDWORD(result) = v18 != 0;
    if ( !v18 )
      break;
    if ( v19 )
    {
      v9 = v18 + *(_DWORD *)(v19 + 4);
      v8 = v9;
    }
    else
    {
      v8 = 0;
    }
    v17[3] = v8 + 8;
    v15 = *(_DWORD *)(v8 + 20);
    if ( v15 == v10[762] )
    {
      SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::iterator_base::operator++(&v18);
    }
    else
    {
      if ( v19 )
      {
        v7 = v18 + *(_DWORD *)(v19 + 4);
        v6 = v7;
      }
      else
      {
        v6 = 0;
      }
      v14 = *(_DWORD *)(v6 + 64);
      v17[0] = v14;
      SpeedTree::CArray<SpeedTree::CGrassCell *,1>::push_back(v17);
      v11 = &v4;
      v12 = v19;
      v13 = v18;
      v5 = (int *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::erase(v16, v18, v19);
      v3 = v5[1];
      v18 = *v5;
      v19 = v3;
    }
  }
  return result;
}
