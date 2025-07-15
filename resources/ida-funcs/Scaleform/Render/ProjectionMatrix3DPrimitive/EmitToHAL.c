void __thiscall Scaleform::Render::ProjectionMatrix3DPrimitive::EmitToHAL(
        Scaleform::Render::ProjectionMatrix3DPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ProjectionMatrix.M[3][2]) )
    Scaleform::Render::HAL::PushProj3D(qp->pHAL, (const __m128i *)&this->Scaleform::Render::RenderQueueItem::Interface);
  else
    Scaleform::Render::HAL::PopProj3D(qp->pHAL);
}
