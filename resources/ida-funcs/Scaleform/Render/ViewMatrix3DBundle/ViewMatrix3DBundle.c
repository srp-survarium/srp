void __thiscall Scaleform::Render::ViewMatrix3DBundle::ViewMatrix3DBundle(
        Scaleform::Render::ViewMatrix3DBundle *this,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::Matrix3x4Ref<float> *pvm)
{
  __m128i dst[3]; // [esp+10h] [ebp-30h] BYREF

  this->__vftable = (Scaleform::Render::ViewMatrix3DBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->RefCount = 1;
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->__vftable = (Scaleform::Render::ViewMatrix3DBundle_vtbl *)&Scaleform::Render::ProjectionMatrix3DBundle::`vftable';
  this->Prim.__vftable = (Scaleform::Render::ViewMatrix3DPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Prim.RefCount = 1;
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Prim.__vftable = (Scaleform::Render::ViewMatrix3DPrimitive_vtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,68>'};
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->Prim.pHAL = hal;
  memset((int)&this->Prim.ViewMatrix, 0, sizeof(this->Prim.ViewMatrix));
  this->Prim.ViewMatrix.M[0][0] = 1.0;
  this->Prim.ViewMatrix.M[1][1] = 1.0;
  this->Prim.ViewMatrix.M[2][2] = 1.0;
  this->Prim.bHasViewMatrix = 0;
  if ( pvm )
  {
    memcpy((int)dst, (const __m128i *)&pvm->Scaleform::Render::Matrix3x4<float>, sizeof(dst));
    memcpy((int)&this->Prim.ViewMatrix, dst, sizeof(this->Prim.ViewMatrix));
    this->Prim.bHasViewMatrix = 1;
  }
}
