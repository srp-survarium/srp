void __thiscall Scaleform::GFx::DrawingContext::ComputeBound(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::Render::Rect<float> *pRect)
{
  unsigned int v3; // edi
  _DWORD *v4; // eax
  int v5; // eax
  unsigned int Size; // [esp+20h] [ebp-14h]
  Scaleform::Render::Rect<float> left; // [esp+24h] [ebp-10h] BYREF

  Scaleform::GFx::DrawingContext::UpdateRenderNode(this, (int)this);
  v3 = 0;
  Size = Scaleform::Render::TreeContainer::GetSize(this->pTreeContainer.pObject);
  if ( Size )
  {
    do
    {
      v4 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int)this->pTreeContainer.pObject & 0xFFFFF000) + 0x10)
                                + 4
                                * ((int)((int)&this->pTreeContainer.pObject[-1]
                                       - ((int)this->pTreeContainer.pObject & 0xFFFFF000))
                                 / 28)
                                + 20)
                    + 144);
      if ( (*(_BYTE *)v4 & 1) != 0 )
        v4 = (_DWORD *)((*v4 & 0xFFFFFFFE) + 8);
      v5 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((v4[v3] & 0xFFFFF000) + 0x10)
                                 + 4 * ((int)(v4[v3] - (v4[v3] & 0xFFFFF000) - 28) / 28)
                                 + 20)
                     + 144);
      (*(void (__thiscall **)(int, Scaleform::Render::Rect<float> *))(*(_DWORD *)(v5 + 8) + 20))(v5 + 8, &left);
      if ( v3 )
        Scaleform::Render::Rect<float>::Union(pRect, left.x1, left.y1, left.x2, left.y2);
      else
        *pRect = left;
      ++v3;
    }
    while ( v3 < Size );
  }
}
