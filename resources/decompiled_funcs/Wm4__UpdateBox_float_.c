void __usercall Wm4::UpdateBox_float_(
        Wm4::Vector2<float> *rkRPoint@<eax>,
        vostok::math::float2 *rkV@<ecx>,
        vostok::math::float2 *rkBox@<edi>,
        Wm4::Vector2<float> *rkLPoint,
        Wm4::Vector2<float> *rkBPoint,
        Wm4::Vector2<float> *rkTPoint,
        vostok::math::float2 *rkU,
        float *rfMinAreaDiv4)
{
  double v10; // st7
  Wm4::Vector2<float> *v11; // esi
  Wm4::Vector2<float> *v12; // eax
  Wm4::Vector2<float> *v13; // eax
  vostok::math::float2 *v14; // eax
  const Wm4::Vector2<float> *v15; // [esp+0h] [ebp-2Ch]
  const Wm4::Vector2<float> *v16; // [esp+0h] [ebp-2Ch]
  const Wm4::Vector2<float> *v17; // [esp+0h] [ebp-2Ch]
  const Wm4::Vector2<float> *v18; // [esp+0h] [ebp-2Ch]
  const Wm4::Vector2<float> *v19; // [esp+0h] [ebp-2Ch]
  Wm4::Vector2<float> fExtent0; // [esp+Ch] [ebp-20h] BYREF
  float fAreaDiv4[2]; // [esp+14h] [ebp-18h] BYREF
  Wm4::Vector2<float> kLBDiff; // [esp+1Ch] [ebp-10h] BYREF
  Wm4::Vector2<float> v23; // [esp+24h] [ebp-8h] BYREF
  float fExtent1a; // [esp+3Ch] [ebp+10h]
  float fExtent1b; // [esp+3Ch] [ebp+10h]
  float fExtent1; // [esp+3Ch] [ebp+10h]
  float fExtent1c; // [esp+3Ch] [ebp+10h]
  float fExtent1d; // [esp+3Ch] [ebp+10h]

  Wm4::Vector2<float>::operator-(rkLPoint, (Wm4::Vector2<float> *)fAreaDiv4, rkRPoint, v15);
  Wm4::Vector2<float>::operator-(rkBPoint, &kLBDiff, rkTPoint, v16);
  fExtent1a = rkU->y * fAreaDiv4[1] + rkU->x * fAreaDiv4[0];
  fExtent0.m_afTuple[0] = fExtent1a * 0.5;
  fExtent1b = rkV->y * kLBDiff.m_afTuple[1] + rkV->x * kLBDiff.m_afTuple[0];
  fExtent1 = 0.5 * fExtent1b;
  fAreaDiv4[0] = fExtent1 * fExtent0.m_afTuple[0];
  if ( *rfMinAreaDiv4 > (double)fAreaDiv4[0] )
  {
    *rfMinAreaDiv4 = fAreaDiv4[0];
    Wm4::Vector2<float>::operator=(rkU, rkBox + 1);
    Wm4::Vector2<float>::operator=(rkV, rkBox + 2);
    rkBox[3].x = fExtent0.m_afTuple[0];
    rkBox[3].y = fExtent1;
    Wm4::Vector2<float>::operator-(rkBPoint, &kLBDiff, rkLPoint, v17);
    v10 = fExtent1;
    fExtent1c = rkV->y * kLBDiff.m_afTuple[1] + rkV->x * kLBDiff.m_afTuple[0];
    fExtent1d = v10 - fExtent1c;
    v11 = (Wm4::Vector2<float> *)Wm4::Vector2<float>::operator*(kLBDiff.m_afTuple, &rkV->x, fExtent1d);
    v12 = (Wm4::Vector2<float> *)Wm4::Vector2<float>::operator*(fAreaDiv4, &rkU->x, fExtent0.m_afTuple[0]);
    v13 = Wm4::Vector2<float>::operator+(v12, &fExtent0, rkLPoint, v18);
    v14 = (vostok::math::float2 *)Wm4::Vector2<float>::operator+(v11, &v23, v13, v19);
    Wm4::Vector2<float>::operator=(v14, rkBox);
  }
}
