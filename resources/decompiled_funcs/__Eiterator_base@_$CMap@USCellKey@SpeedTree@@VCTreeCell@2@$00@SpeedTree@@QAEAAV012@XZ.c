int *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::iterator_base::operator++(int *this)
{
  int v2; // [esp+0h] [ebp-38h]
  int v3; // [esp+4h] [ebp-34h]
  int v4; // [esp+8h] [ebp-30h]
  int v5; // [esp+Ch] [ebp-2Ch]
  int v6; // [esp+10h] [ebp-28h]
  int v7; // [esp+14h] [ebp-24h]
  int v8; // [esp+18h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-1Ch]
  int v10; // [esp+20h] [ebp-18h]
  int v11; // [esp+24h] [ebp-14h]
  int v12; // [esp+28h] [ebp-10h]
  int v13; // [esp+2Ch] [ebp-Ch]
  int v14; // [esp+34h] [ebp-4h]

  if ( this[1] )
  {
    if ( *this )
      v13 = *this + *(_DWORD *)(this[1] + 4);
    else
      v13 = 0;
    v12 = v13;
  }
  else
  {
    v12 = 0;
  }
  if ( *(_DWORD *)(v12 + 148) )
  {
    if ( this[1] )
    {
      if ( *this )
        v7 = *this + *(_DWORD *)(this[1] + 4);
      else
        v7 = 0;
      v6 = v7;
    }
    else
    {
      v6 = 0;
    }
    for ( *this = *(_DWORD *)(v6 + 148); ; *this = *(_DWORD *)(v2 + 144) )
    {
      if ( this[1] )
      {
        v5 = *this ? *this + *(_DWORD *)(this[1] + 4) : 0;
        v4 = v5;
      }
      else
      {
        v4 = 0;
      }
      if ( !*(_DWORD *)(v4 + 144) )
        break;
      if ( this[1] )
      {
        if ( *this )
          v3 = *this + *(_DWORD *)(this[1] + 4);
        else
          v3 = 0;
        v2 = v3;
      }
      else
      {
        v2 = 0;
      }
    }
  }
  else
  {
    v14 = 0;
    while ( *this )
    {
      if ( this[1] )
      {
        v11 = *this ? *this + *(_DWORD *)(this[1] + 4) : 0;
        v10 = v11;
      }
      else
      {
        v10 = 0;
      }
      if ( v14 != *(_DWORD *)(v10 + 148) )
        break;
      v14 = *this;
      if ( this[1] )
      {
        if ( *this )
          v9 = *this + *(_DWORD *)(this[1] + 4);
        else
          v9 = 0;
        v8 = v9;
      }
      else
      {
        v8 = 0;
      }
      *this = *(_DWORD *)(v8 + 152);
    }
  }
  return this;
}
