void __thiscall Scaleform::Render::RectPacker::Pack(Scaleform::Render::RectPacker *this)
{
  Scaleform::Render::RectPacker::RectType **Pages; // edx
  unsigned int v3; // eax
  unsigned int NumPacked; // eax
  unsigned int Width; // ecx
  unsigned int Height; // edx
  unsigned int v7; // esi
  unsigned int Size; // esi
  unsigned int v9; // ecx
  unsigned int v10; // edi
  Scaleform::Render::RectPacker::PackType *v11; // edi
  unsigned int v12; // eax
  unsigned int v13; // [esp+8h] [ebp-28h]
  unsigned int v14; // [esp+10h] [ebp-20h]
  _DWORD v15[7]; // [esp+14h] [ebp-1Ch] BYREF

  this->PackedRects.Size = 0;
  this->Packs.Size = 0;
  this->PackTree.Size = 0;
  if ( this->SrcRects.Size )
  {
    Scaleform::Alg::QuickSortSliced<Scaleform::ArrayPagedLH_POD<Scaleform::Render::RectPacker::RectType,8,64,2>,bool (__cdecl *)(Scaleform::Render::RectPacker::RectType const &,Scaleform::Render::RectPacker::RectType const &)>(
      &this->SrcRects,
      0,
      this->SrcRects.Size,
      (bool (__cdecl *)(const Scaleform::Render::RectPacker::RectType *, const Scaleform::Render::RectPacker::RectType *))Scaleform::Render::RectPacker::cmpRects);
    Pages = this->SrcRects.Pages;
    v3 = this->SrcRects.Size - 1;
    this->MinWidth = Pages[v3 >> 8][(unsigned __int8)(LOBYTE(this->SrcRects.Size) - 1)].x;
    this->MinHeight = Pages[v3 >> 8][(unsigned __int8)v3].y;
    this->NumPacked = 0;
    do
    {
      NumPacked = this->NumPacked;
      Width = this->Width;
      Height = this->Height;
      this->PackTree.Size = 0;
      v15[0] = 0;
      v15[1] = 0;
      v13 = NumPacked;
      v7 = this->PackTree.Size >> 8;
      v15[2] = Width;
      v15[3] = Height;
      memset(&v15[4], 255, 12);
      if ( v7 >= this->PackTree.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2>>::allocatePage(
          &this->PackTree,
          v7);
      qmemcpy(
        &this->PackTree.Pages[v7][(unsigned __int8)this->PackTree.Size++],
        v15,
        sizeof(this->PackTree.Pages[v7][(unsigned __int8)this->PackTree.Size++]));
      Scaleform::Render::RectPacker::packRects(this, 0, 0);
      if ( this->NumPacked > v13 )
      {
        Size = this->PackedRects.Size;
        Scaleform::Render::RectPacker::emitPacked(this);
        v9 = this->PackedRects.Size - Size;
        v10 = this->Packs.Size >> 4;
        v14 = v9;
        if ( v10 >= this->Packs.NumPages )
        {
          Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::PackType,4,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::PackType,2>>::allocatePage(
            &this->Packs,
            v10);
          v9 = v14;
        }
        v11 = this->Packs.Pages[v10];
        v12 = this->Packs.Size & 0xF;
        v11[v12].StartRect = Size;
        v11[v12].NumRects = v9;
        ++this->Packs.Size;
      }
    }
    while ( this->NumPacked < this->SrcRects.Size );
  }
}
