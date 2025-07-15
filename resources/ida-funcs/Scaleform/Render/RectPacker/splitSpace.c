void __thiscall Scaleform::Render::RectPacker::splitSpace(
        Scaleform::Render::RectPacker *this,
        unsigned int nodeIdx,
        const Scaleform::Render::RectPacker::RectType *rect)
{
  Scaleform::Render::RectPacker *v3; // eax
  Scaleform::Render::RectPacker::NodeType *v4; // ebp
  unsigned int x; // edx
  unsigned int y; // ecx
  unsigned int Size; // esi
  Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2> > *p_PackTree; // ebx
  unsigned int v9; // esi
  unsigned int v10; // esi
  _DWORD v12[7]; // [esp+14h] [ebp-38h] BYREF
  _DWORD v13[7]; // [esp+30h] [ebp-1Ch] BYREF

  v3 = this;
  v4 = &this->PackTree.Pages[nodeIdx >> 8][(unsigned __int8)nodeIdx];
  qmemcpy(v12, v4, sizeof(v12));
  qmemcpy(v13, v4, sizeof(v13));
  x = rect->x;
  y = rect->y;
  Size = v3->PackTree.Size;
  v12[0] += rect->x;
  v12[2] -= x;
  v13[1] += y;
  v13[3] -= y;
  p_PackTree = &v3->PackTree;
  v9 = Size >> 8;
  v12[3] = y;
  if ( v9 >= v3->PackTree.NumPages )
  {
    Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2>>::allocatePage(
      &v3->PackTree,
      v9);
    v3 = this;
  }
  qmemcpy(
    &p_PackTree->Pages[v9][(unsigned __int8)p_PackTree->Size++],
    v12,
    sizeof(p_PackTree->Pages[v9][(unsigned __int8)p_PackTree->Size++]));
  v10 = p_PackTree->Size >> 8;
  if ( v10 >= p_PackTree->NumPages )
  {
    Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2>>::allocatePage(
      p_PackTree,
      p_PackTree->Size >> 8);
    v3 = this;
  }
  qmemcpy(
    &p_PackTree->Pages[v10][(unsigned __int8)p_PackTree->Size++],
    v13,
    sizeof(p_PackTree->Pages[v10][(unsigned __int8)p_PackTree->Size++]));
  *(Scaleform::Render::RectPacker::RectType *)&v4->Width = *rect;
  v4->Node1 = v3->PackTree.Size - 2;
  v4->Node2 = v3->PackTree.Size - 1;
}
