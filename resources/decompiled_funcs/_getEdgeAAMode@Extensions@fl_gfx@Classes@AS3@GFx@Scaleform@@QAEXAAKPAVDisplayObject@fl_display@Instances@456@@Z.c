void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::Extensions::getEdgeAAMode(
        Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *this,
        unsigned int *result,
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *dispObj)
{
  unsigned int RenderNode; // eax
  int v5; // eax

  RenderNode = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetRenderNode(dispObj->pDispObj.pObject);
  v5 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)((RenderNode & 0xFFFFF000) + 0x10)
                            + 4 * ((int)(RenderNode - (RenderNode & 0xFFFFF000) - 28) / 28)
                            + 20)
                + 6)
     & 0xC;
  switch ( v5 )
  {
    case 4:
      *result = this->EDGEAA_ON;
      break;
    case 8:
      *result = this->EDGEAA_OFF;
      break;
    case 12:
      *result = this->EDGEAA_DISABLE;
      break;
    default:
      *result = this->EDGEAA_INHERIT;
      break;
  }
}
