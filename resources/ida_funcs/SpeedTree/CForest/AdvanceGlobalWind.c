void __usercall SpeedTree::CForest::AdvanceGlobalWind(SpeedTree::CForest *this@<ecx>, int a2@<esi>)
{
  unsigned int i; // edi
  SpeedTree::CWind *Wind; // eax
  char v4; // [esp-4h] [ebp-Ch]
  float v5; // [esp+0h] [ebp-8h]

  SpeedTree::CWind::Advance((SpeedTree::CWind *)(a2 + 124), *(_BYTE *)(a2 + 100), *(float *)(a2 + 120));
  for ( i = 0; i < *(_DWORD *)(a2 + 12); ++i )
  {
    v5 = *(float *)(a2 + 120);
    v4 = *(_BYTE *)(a2 + 100);
    Wind = SpeedTree::CCore::GetWind(*(SpeedTree::CCore **)(*(_DWORD *)(a2 + 8) + 4 * i));
    SpeedTree::CWind::Advance(Wind, v4, v5);
  }
}
