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
  Scaleform::Render::RectPacker::NodeType node1; // [esp+14h] [ebp-38h] BYREF
  Scaleform::Render::RectPacker::NodeType node2; // [esp+30h] [ebp-1Ch] BYREF

  v3 = this;
  v4 = &this->PackTree.Pages[nodeIdx >> 8][(unsigned __int8)nodeIdx];
  qmemcpy(&node1, v4, sizeof(node1));
  qmemcpy(&node2, v4, sizeof(node2));
  x = rect->x;
  y = rect->y;
  Size = v3->PackTree.Size;
  node1.x += rect->x;
  node1.Width -= x;
  node2.y += y;
  node2.Height -= y;
  p_PackTree = &v3->PackTree;
  v9 = Size >> 8;
  node1.Height = y;
  if ( v9 >= v3->PackTree.NumPages )
  {
    Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::NodeType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::NodeType,2>>::allocatePage(
      &v3->PackTree,
      v9);
    v3 = this;
  }
  qmemcpy(
    &p_PackTree->Pages[v9][(unsigned __int8)p_PackTree->Size++],
    &node1,
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
    &node2,
    sizeof(p_PackTree->Pages[v10][(unsigned __int8)p_PackTree->Size++]));
  *(Scaleform::Render::RectPacker::RectType *)&v4->Width = *rect;
  v4->Node1 = v3->PackTree.Size - 2;
  v4->Node2 = v3->PackTree.Size - 1;
}
