void __thiscall SpeedTree::CParser::ConvertUint8Array(SpeedTree::CParser *this, unsigned __int8 *a2, int a3, int a4)
{
  float v5; // [esp+64h] [ebp-2Ch]
  float v6; // [esp+68h] [ebp-28h]
  float v7; // [esp+6Ch] [ebp-24h]
  struct SpeedTree::Vec3 v8; // [esp+70h] [ebp-20h] BYREF
  struct SpeedTree::Vec3 v9; // [esp+7Ch] [ebp-14h]
  int i; // [esp+88h] [ebp-8h]
  int v11; // [esp+8Ch] [ebp-4h]

  v11 = a4 + 3;
  for ( i = 0; i < a3; ++i )
  {
    v7 = (double)a2[2] / 255.0 * 2.0 - 1.0;
    v6 = (double)a2[1] / 255.0 * 2.0 - 1.0;
    v5 = (double)*a2 / 255.0 * 2.0 - 1.0;
    v9.x = v5;
    v9.y = v6;
    v9.z = v7;
    SpeedTree::CParser::ConvertCoord(this, &v8, v5, v6, v7);
    v9 = v8;
    *a2 = (int)((v8.x * 0.5 + 0.5) * 255.0);
    a2[1] = (int)((v9.y * 0.5 + 0.5) * 255.0);
    a2[2] = (int)((v9.z * 0.5 + 0.5) * 255.0);
    a2 += v11;
  }
}
