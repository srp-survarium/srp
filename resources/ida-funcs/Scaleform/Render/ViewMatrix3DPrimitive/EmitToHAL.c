void __thiscall Scaleform::Render::ViewMatrix3DPrimitive::EmitToHAL(
        Scaleform::Render::ViewMatrix3DPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ViewMatrix.M[2][2]) )
    Scaleform::Render::HAL::PushView3D(qp->pHAL, (const __m128i *)&this->Scaleform::Render::RenderQueueItem::Interface);
  else
    Scaleform::Render::HAL::PopView3D(qp->pHAL);
}
