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
  _WORD v10[2]; // [esp+10h] [ebp-1Ch] BYREF
  float v11; // [esp+14h] [ebp-18h] BYREF
  Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeRef key; // [esp+18h] [ebp-14h] BYREF
  Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+20h] [ebp-Ch] BYREF

  v1 = 0;
  WinHDC = this->pSysData->WinHDC;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  KerningPairsW = GetKerningPairsW(WinHDC, 0, 0);
  if ( KerningPairsW )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      KerningPairsW + (KerningPairsW >> 2));
    v1 = KerningPairsW;
    GetKerningPairsW(this->pSysData->WinHDC, KerningPairsW, pheapAddr.Data);
  }
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear(&this->KerningPairs.mHash);
  if ( v1 )
  {
    key.pFirst = (const Scaleform::Render::ExternalFontWinAPI::KerningPairType *)v10;
    key.pSecond = &v11;
    p_iKernAmount = &pheapAddr.Data->iKernAmount;
    do
    {
      v10[0] = *((_WORD *)p_iKernAmount - 2);
      v10[1] = *((_WORD *)p_iKernAmount - 1);
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
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
}
