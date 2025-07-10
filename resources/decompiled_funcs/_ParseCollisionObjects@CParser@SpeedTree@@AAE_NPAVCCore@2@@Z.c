char __thiscall SpeedTree::CParser::ParseCollisionObjects(SpeedTree::CParser *this, struct SpeedTree::CCore *a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  struct SpeedTree::Vec3 *v9; // eax
  struct SpeedTree::Vec3 *v10; // eax
  struct SpeedTree::Vec3 v13; // [esp+158h] [ebp-24h] BYREF
  struct SpeedTree::Vec3 v14; // [esp+164h] [ebp-18h] BYREF
  SpeedTree::SCollisionObject *v15; // [esp+170h] [ebp-Ch]
  int i; // [esp+174h] [ebp-8h]
  char v17; // [esp+17Bh] [ebp-1h]

  v17 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 4) )
  {
    a2->m_nNumCollisionObjects = SpeedTree::CParser::ParseInt(this);
    if ( a2->m_nNumCollisionObjects <= 0 )
    {
      if ( !a2->m_nNumCollisionObjects )
        return 1;
    }
    else
    {
      a2->m_pCollisionObjects = (SpeedTree::SCollisionObject *)SpeedTree::st_new_array<SpeedTree::SCollisionObject>(a2->m_nNumCollisionObjects);
      for ( i = 0; i < a2->m_nNumCollisionObjects; ++i )
      {
        v15 = &a2->m_pCollisionObjects[i];
        v2 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter1.x = v2;
        v3 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter1.y = v3;
        v4 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter1.z = v4;
        v5 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter2.x = v5;
        v6 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter2.y = v6;
        v7 = SpeedTree::CParser::ParseFloat(this);
        v15->m_vCenter2.z = v7;
        v8 = SpeedTree::CParser::ParseFloat(this);
        v15->m_fRadius = v8;
        v17 = SpeedTree::CParser::ParseString(v15, 256);
        if ( *((_DWORD *)this + 22) )
        {
          v9 = SpeedTree::CParser::ConvertCoord(this, &v14, &v15->m_vCenter1.x);
          v15->m_vCenter1 = *v9;
          v10 = SpeedTree::CParser::ConvertCoord(this, &v13, &v15->m_vCenter2.x);
          v15->m_vCenter2 = *v10;
        }
      }
    }
  }
  return v17;
}
