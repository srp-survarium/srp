char __thiscall SpeedTree::CForest::ReplaceTree(
        SpeedTree::CForest *this,
        const struct SpeedTree::CCore *a2,
        struct SpeedTree::CCore *a3)
{
  char v4; // [esp+7h] [ebp-6Dh]
  SpeedTree::CArray<SpeedTree::CInstance,1> v6; // [esp+50h] [ebp-24h] BYREF
  char v7; // [esp+66h] [ebp-Eh]
  char v8; // [esp+67h] [ebp-Dh]
  int v9; // [esp+70h] [ebp-4h]

  v8 = 0;
  if ( a2 && a3 && a2 != a3 )
  {
    if ( SpeedTree::CForest::TreeIsRegistered(this, a2) )
    {
      if ( SpeedTree::CForest::TreeIsRegistered(this, a3) )
        v4 = 1;
      else
        v4 = SpeedTree::CForest::RegisterTree(this, a3);
      v7 = v4;
      if ( v4 )
      {
        v6.__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
        memset(&v6.m_pData, 0, 13);
        v9 = 0;
        if ( SpeedTree::CForest::GetInstances(a2, &v6) )
        {
          if ( v6.m_uiSize )
          {
            if ( SpeedTree::CForest::AddInstances(this, a3, v6.m_pData, v6.m_uiSize) )
              v8 = 1;
          }
          else
          {
            v8 = 1;
          }
        }
        if ( !SpeedTree::CForest::UnregisterTree(this, a2) )
        {
          SpeedTree::CCore::SetError("CForest::ChangeTree, failed to unregister old tree");
          v8 = 0;
        }
        v9 = -1;
        v6.__vftable = (SpeedTree::CArray<SpeedTree::CInstance,1>_vtbl *)&SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
        if ( v6.m_bExternalMemory )
          SpeedTree::CArray<SpeedTree::CInstance,1>::SetExternalMemory(&v6, 0, 0);
        SpeedTree::CArray<SpeedTree::CInstance,1>::clear(&v6);
      }
      else
      {
        SpeedTree::CCore::SetError("CForest::ChangeTree, failed to register new tree");
      }
    }
    else
    {
      SpeedTree::CCore::SetError("CForest::ChangeTree, old tree pointer was not registered with CForest::RegisterTree");
    }
  }
  else
  {
    SpeedTree::CCore::SetError("CForest::ChangeTree, NULL CTree pointer passed in");
  }
  return v8;
}
