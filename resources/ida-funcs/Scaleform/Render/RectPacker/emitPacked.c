void __thiscall Scaleform::Render::RectPacker::emitPacked(Scaleform::Render::RectPacker *this)
{
  unsigned int v1; // edx
  Scaleform::Render::RectPacker::NodeType *v2; // eax
  unsigned int Id; // ebx
  unsigned int x; // ebp
  Scaleform::ArrayPagedLH_POD<Scaleform::Render::RectPacker::RectType,8,64,2> *p_PackedRects; // esi
  unsigned int v6; // edi
  Scaleform::Render::RectPacker::RectType *v7; // eax
  unsigned int i; // [esp+0h] [ebp-14h]
  Scaleform::Render::RectPacker *v9; // [esp+4h] [ebp-10h]
  unsigned int y; // [esp+Ch] [ebp-8h]

  v1 = 0;
  v9 = this;
  for ( i = 0; v1 < this->PackTree.Size; i = v1 )
  {
    v2 = &this->PackTree.Pages[v1 >> 8][(unsigned __int8)v1];
    Id = v2->Id;
    if ( Id != -1 )
    {
      x = v2->x;
      p_PackedRects = &this->PackedRects;
      v6 = this->PackedRects.Size >> 8;
      y = v2->y;
      if ( v6 >= this->PackedRects.NumPages )
      {
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2>>::allocatePage(
          &this->PackedRects,
          v6);
        this = v9;
      }
      v7 = &p_PackedRects->Pages[v6][(unsigned __int8)p_PackedRects->Size];
      v7->x = x;
      v7->y = y;
      v1 = i;
      v7->Id = Id;
      ++p_PackedRects->Size;
    }
    ++v1;
  }
}
