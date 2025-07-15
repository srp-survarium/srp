void __thiscall Scaleform::GFx::Stream::ReadMatrix(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Matrix2x4<float> *pm)
{
  signed int UInt; // ebx
  int v5; // eax
  int v6; // ebp
  int v7; // eax
  signed int v8; // ebx
  int v9; // eax
  int v10; // ebp
  int v11; // eax
  signed int v12; // eax
  signed int v13; // ebx
  int v14; // eax
  int v15; // ebp
  int v16; // eax
  Scaleform::Render::Matrix2x4<float> *pma; // [esp+14h] [ebp+4h]
  Scaleform::Render::Matrix2x4<float> *pmb; // [esp+14h] [ebp+4h]
  Scaleform::Render::Matrix2x4<float> *pmc; // [esp+14h] [ebp+4h]
  Scaleform::Render::Matrix2x4<float> *pmd; // [esp+14h] [ebp+4h]
  Scaleform::Render::Matrix2x4<float> *pme; // [esp+14h] [ebp+4h]
  Scaleform::Render::Matrix2x4<float> *pmf; // [esp+14h] [ebp+4h]

  this->UnusedBits = 0;
  pm->M[0][0] = 1.0;
  pm->M[0][1] = 0.0;
  pm->M[0][2] = 0.0;
  pm->M[0][3] = 0.0;
  pm->M[1][0] = 0.0;
  pm->M[1][2] = 0.0;
  pm->M[1][3] = 0.0;
  pm->M[1][1] = 1.0;
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    UInt = Scaleform::GFx::Stream::ReadUInt(this, 5);
    v5 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v6 = 1 << (UInt - 1);
    pma = (Scaleform::Render::Matrix2x4<float> *)v5;
    if ( (v6 & v5) != 0 )
      pma = (Scaleform::Render::Matrix2x4<float> *)((-1 << UInt) | v5);
    pm->M[0][0] = (double)(int)pma * 0.0000152587890625;
    v7 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    pmb = (Scaleform::Render::Matrix2x4<float> *)v7;
    if ( (v6 & v7) != 0 )
      pmb = (Scaleform::Render::Matrix2x4<float> *)((-1 << UInt) | v7);
    pm->M[1][1] = (double)(int)pmb * 0.0000152587890625;
  }
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    v8 = Scaleform::GFx::Stream::ReadUInt(this, 5);
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    v10 = 1 << (v8 - 1);
    pmc = (Scaleform::Render::Matrix2x4<float> *)v9;
    if ( (v10 & v9) != 0 )
      pmc = (Scaleform::Render::Matrix2x4<float> *)((-1 << v8) | v9);
    pm->M[1][0] = (double)(int)pmc * 0.0000152587890625;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    pmd = (Scaleform::Render::Matrix2x4<float> *)v11;
    if ( (v10 & v11) != 0 )
      pmd = (Scaleform::Render::Matrix2x4<float> *)((-1 << v8) | v11);
    pm->M[0][1] = (double)(int)pmd * 0.0000152587890625;
  }
  v12 = Scaleform::GFx::Stream::ReadUInt(this, 5);
  v13 = v12;
  if ( v12 > 0 )
  {
    v14 = Scaleform::GFx::Stream::ReadUInt(this, v12);
    v15 = 1 << (v13 - 1);
    pme = (Scaleform::Render::Matrix2x4<float> *)v14;
    if ( (v15 & v14) != 0 )
      pme = (Scaleform::Render::Matrix2x4<float> *)((-1 << v13) | v14);
    pm->M[0][3] = (float)(int)pme;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v13);
    pmf = (Scaleform::Render::Matrix2x4<float> *)v16;
    if ( (v15 & v16) != 0 )
      pmf = (Scaleform::Render::Matrix2x4<float> *)((-1 << v13) | v16);
    pm->M[1][3] = (float)(int)pmf;
  }
}
