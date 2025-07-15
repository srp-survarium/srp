void __thiscall Scaleform::GFx::AS3::ShapeObject::SetRatio(Scaleform::GFx::AS3::ShapeObject *this, float f)
{
  unsigned int RenderNode; // eax

  RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  if ( RenderNode )
  {
    if ( *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                              + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                              + 20)
                  + 4) == 3 )
      *(float *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this->pRenNode.pObject, 0x10u)[18].Type = f;
  }
}
