char __userpurge Scaleform::GFx::DrawingContext::DefPointTestLocal@<al>(
        Scaleform::GFx::DrawingContext *this@<ecx>,
        int a2@<ebx>,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        const Scaleform::GFx::DisplayObjectBase *pinst)
{
  Scaleform::GFx::DrawingContext *v5; // esi
  int v6; // edi
  _DWORD *v7; // eax
  int v8; // esi
  unsigned int Size; // [esp+40h] [ebp-18h]
  float v12[4]; // [esp+48h] [ebp-10h] BYREF

  v5 = this;
  Scaleform::GFx::DrawingContext::UpdateRenderNode(this, a2);
  v6 = 0;
  Size = Scaleform::Render::TreeContainer::GetSize(v5->pTreeContainer.pObject);
  if ( !Size )
    return 0;
  while ( 1 )
  {
    v7 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int)v5->pTreeContainer.pObject & 0xFFFFF000) + 0x10)
                              + 4
                              * ((int)((int)&v5->pTreeContainer.pObject[-1]
                                     - ((int)v5->pTreeContainer.pObject & 0xFFFFF000))
                               / 28)
                              + 20)
                  + 144);
    if ( (*(_BYTE *)v7 & 1) != 0 )
      v7 = (_DWORD *)((*v7 & 0xFFFFFFFE) + 8);
    v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((v7[v6] & 0xFFFFF000) + 0x10)
                               + 4 * ((int)(v7[v6] - (v7[v6] & 0xFFFFF000) - 28) / 28)
                               + 20)
                   + 144);
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)(v8 + 8) + 20))(v8 + 8, v12);
    if ( v12[2] >= (double)pt->x && v12[0] <= (double)pt->x && v12[3] >= (double)pt->y && v12[1] <= (double)pt->y )
      break;
    if ( ++v6 >= Size )
      return 0;
    v5 = this;
  }
  if ( testShape )
    return Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
             *(const Scaleform::Render::ShapeDataInterface **)(v8 + 44),
             &Scaleform::Render::Matrix2x4<float>::Identity,
             pt->x,
             pt->y);
  else
    return 1;
}
