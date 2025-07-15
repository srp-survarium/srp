unsigned int __thiscall Scaleform::Render::ExternalFontWinAPI::GetGlyphIndex(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned __int16 code)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // edi
  int Index; // eax
  unsigned int *v5; // edi
  unsigned int v6; // esi
  HDC__ *WinHDC; // edi
  HGDIOBJ v9; // eax
  Scaleform::Render::FontSysDataWinAPI *pSysData; // edx
  double Scale1024; // st7
  unsigned int Size; // esi
  Scaleform::Lock *lpCriticalSection; // [esp+154h] [ebp-5Ch]
  unsigned int gmCellIncX; // [esp+158h] [ebp-58h] BYREF
  Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeRef key; // [esp+15Ch] [ebp-54h] BYREF
  HGDIOBJ h; // [esp+168h] [ebp-48h]
  MAT2 mat2; // [esp+16Ch] [ebp-44h] BYREF
  _GLYPHMETRICS v18; // [esp+17Ch] [ebp-34h] BYREF
  Scaleform::Render::ExternalFontWinAPI::GlyphType val; // [esp+190h] [ebp-20h] BYREF

  if ( !this->MasterFont )
    return -1;
  lpCriticalSection = this->pFontLock;
  EnterCriticalSection(&lpCriticalSection->cs);
  pTable = this->CodeTable.mHash.pTable;
  if ( pTable )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::findIndexCore<unsigned short>(
              &this->CodeTable.mHash,
              &code,
              code & pTable->SizeMask);
    if ( Index >= 0 )
    {
      v5 = &pTable[1].SizeMask + 3 * Index;
      if ( v5 )
      {
        if ( v5 != (unsigned int *)-4 )
        {
          v6 = v5[1];
          LeaveCriticalSection(&lpCriticalSection->cs);
          return v6;
        }
      }
    }
  }
  WinHDC = this->pSysData->WinHDC;
  v9 = SelectObject(WinHDC, this->MasterFont);
  memset(&mat2.eM12, 0, 10);
  h = v9;
  mat2.eM11.value = 1;
  pSysData = this->pSysData;
  mat2.eM11.fract = 0;
  mat2.eM22.value = 1;
  if ( GetGlyphOutlineW(pSysData->WinHDC, code, 0, &v18, 0, 0, &mat2) == -1 )
  {
    SelectObject(WinHDC, h);
    LeaveCriticalSection(&lpCriticalSection->cs);
    return -1;
  }
  Scale1024 = this->Scale1024;
  gmCellIncX = v18.gmCellIncX;
  val.Code = code;
  val.Advance = Scale1024 * (double)v18.gmCellIncX;
  val.Bounds.x1 = (double)v18.gmptGlyphOrigin.x * this->Scale1024;
  val.Bounds.y1 = -(double)v18.gmptGlyphOrigin.y * this->Scale1024;
  val.Bounds.x2 = (double)v18.gmBlackBoxX * this->Scale1024 + val.Bounds.x1;
  val.Bounds.y2 = (double)v18.gmBlackBoxY * this->Scale1024 + val.Bounds.y1;
  Scaleform::ArrayData<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->Glyphs.Data,
    &val);
  gmCellIncX = this->Glyphs.Data.Size - 1;
  key.pFirst = &code;
  key.pSecond = &gmCellIncX;
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
    &this->CodeTable.mHash,
    &this->CodeTable,
    &key,
    code);
  Size = this->Glyphs.Data.Size;
  SelectObject(WinHDC, h);
  LeaveCriticalSection(&lpCriticalSection->cs);
  return Size - 1;
}
