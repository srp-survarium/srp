void __thiscall Scaleform::Render::ProjectionMatrix3DBundle::ProjectionMatrix3DBundle(
        Scaleform::Render::ProjectionMatrix3DBundle *this,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::Matrix4x4Ref<float> *ppm)
{
  __m128i dst[4]; // [esp+10h] [ebp-40h] BYREF

  this->__vftable = (Scaleform::Render::ProjectionMatrix3DBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->RefCount = 1;
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->__vftable = (Scaleform::Render::ProjectionMatrix3DBundle_vtbl *)&Scaleform::Render::ProjectionMatrix3DBundle::`vftable';
  this->Prim.__vftable = (Scaleform::Render::ProjectionMatrix3DPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Prim.RefCount = 1;
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Prim.__vftable = (Scaleform::Render::ProjectionMatrix3DPrimitive_vtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,68>'};
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->Prim.pHAL = hal;
  memset((int)&this->Prim.ProjectionMatrix, 0, sizeof(this->Prim.ProjectionMatrix));
  this->Prim.ProjectionMatrix.M[0][0] = 1.0;
  this->Prim.ProjectionMatrix.M[1][1] = 1.0;
  this->Prim.ProjectionMatrix.M[2][2] = 1.0;
  this->Prim.ProjectionMatrix.M[3][3] = 1.0;
  this->Prim.bHasProjectionMatrix = 0;
  if ( ppm )
  {
    memcpy((int)dst, (const __m128i *)&ppm->Scaleform::Render::Matrix4x4<float>, sizeof(dst));
    memcpy((int)&this->Prim.ProjectionMatrix, dst, sizeof(this->Prim.ProjectionMatrix));
    this->Prim.bHasProjectionMatrix = 1;
  }
}
