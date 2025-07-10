void __thiscall SpeedTree::CGrass::BuildTexCoordTable(SpeedTree::CGrass *this)
{
  double v1; // st7
  double v2; // st7
  unsigned int count; // [esp+2Ch] [ebp-64h]
  float v5; // [esp+5Ch] [ebp-34h] BYREF
  float v6; // [esp+60h] [ebp-30h] BYREF
  float v7; // [esp+64h] [ebp-2Ch] BYREF
  float v8; // [esp+68h] [ebp-28h] BYREF
  signed int k; // [esp+6Ch] [ebp-24h]
  float *v10; // [esp+70h] [ebp-20h]
  int j; // [esp+74h] [ebp-1Ch]
  float v12; // [esp+78h] [ebp-18h]
  int i; // [esp+7Ch] [ebp-14h]
  float v14; // [esp+80h] [ebp-10h]
  float v15; // [esp+84h] [ebp-Ch]
  float v16; // [esp+88h] [ebp-8h]
  float v17; // [esp+8Ch] [ebp-4h]

  SpeedTree::CArray<float,1>::reserve(8 * this->m_nNumImageRows * this->m_nNumImageCols);
  if ( (unsigned __int8)SpeedTree::CArray<float,1>::reserve(0) )
    this->m_aBladeTexCoords.m_uiSize = 0;
  else
    this->m_aBladeTexCoords.m_uiSize = this->m_aBladeTexCoords.m_uiDataSize;
  v15 = 0.0062500001;
  v14 = 1.0 / (double)this->m_nNumImageCols;
  v17 = 1.0 / (double)this->m_nNumImageRows;
  v16 = 0.0;
  for ( i = 0; i < this->m_nNumImageCols; ++i )
  {
    v12 = 0.0;
    for ( j = 0; j < this->m_nNumImageRows; ++j )
    {
      v8 = v16 + v15;
      SpeedTree::CArray<float,1>::push_back(&v8);
      if ( SpeedTree::CCore::GetTextureFlip() )
        v1 = v12 + v15;
      else
        v1 = 1.0 - (v12 + v15);
      v7 = v1;
      SpeedTree::CArray<float,1>::push_back(&v7);
      v6 = v16 + v14 - v15;
      SpeedTree::CArray<float,1>::push_back(&v6);
      if ( SpeedTree::CCore::GetTextureFlip() )
        v2 = v12 + v17 - v15;
      else
        v2 = 1.0 - (v12 + v17 - v15);
      v5 = v2;
      SpeedTree::CArray<float,1>::push_back(&v5);
      v10 = &this->m_aBladeTexCoords.m_pData[this->m_aBladeTexCoords.m_uiSize - 4];
      SpeedTree::CArray<float,1>::push_back(v10 + 2);
      SpeedTree::CArray<float,1>::push_back(v10 + 1);
      SpeedTree::CArray<float,1>::push_back(v10);
      SpeedTree::CArray<float,1>::push_back(v10 + 3);
      v12 = v12 + v17;
    }
    v16 = v16 + v14;
  }
  count = this->m_aBladeTexCoords.m_uiSize;
  if ( (unsigned __int8)SpeedTree::CArray<unsigned char,1>::reserve(count) )
    this->m_aBladeTexCoordsUChar.m_uiSize = count;
  else
    this->m_aBladeTexCoordsUChar.m_uiSize = this->m_aBladeTexCoordsUChar.m_uiDataSize;
  for ( k = 0; k < (signed int)this->m_aBladeTexCoords.m_uiSize; ++k )
    this->m_aBladeTexCoordsUChar.m_pData[k] = (int)(this->m_aBladeTexCoords.m_pData[k] * 255.0);
}
