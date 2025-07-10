void __thiscall Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(Scaleform::Render::ExternalFontWinAPI *this)
{
  DWORD v1; // edi
  DWORD KerningPairsW; // esi
  int *p_iKernAmount; // esi
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // edx
  HDC__ *WinHDC; // [esp-Ch] [ebp-38h]
  char v9; // [esp+Fh] [ebp-1Dh]
  Scaleform::Render::ExternalFontWinAPI::KerningPairType pair; // [esp+10h] [ebp-1Ch] BYREF
  float v11; // [esp+14h] [ebp-18h] BYREF
  Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeRef key; // [esp+18h] [ebp-14h] BYREF
  Scaleform::Array<tagKERNINGPAIR,2,Scaleform::ArrayDefaultPolicy> pairs; // [esp+20h] [ebp-Ch] BYREF

  v1 = 0;
  WinHDC = this->pSysData->WinHDC;
  memset(&pairs, 0, sizeof(pairs));
  KerningPairsW = GetKerningPairsW(WinHDC, 0, 0);
  if ( KerningPairsW )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pairs.Data,
      &pairs,
      KerningPairsW + (KerningPairsW >> 2));
    v1 = KerningPairsW;
    GetKerningPairsW(this->pSysData->WinHDC, KerningPairsW, pairs.Data.Data);
  }
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear(&this->KerningPairs.mHash);
  if ( v1 )
  {
    key.pFirst = &pair;
    key.pSecond = &v11;
    p_iKernAmount = &pairs.Data.Data->iKernAmount;
    do
    {
      pair = (Scaleform::Render::ExternalFontWinAPI::KerningPairType)*(p_iKernAmount - 1);
      v5 = 4;
      v6 = 5381;
      v11 = (double)*p_iKernAmount * this->Scale1024;
      do
      {
        v7 = (unsigned __int8)*(&v9 + v5--);
        v6 = v7 + 65599 * v6;
      }
      while ( v5 );
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeRef>(
        &this->KerningPairs.mHash,
        &this->KerningPairs,
        &key,
        v6);
      p_iKernAmount += 2;
      --v1;
    }
    while ( v1 );
  }
  if ( pairs.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pairs.Data.Data);
}
