void __thiscall Scaleform::Render::UserDataPrimitive::EmitToHAL(
        Scaleform::Render::UserDataPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::RenderQueueItem::Interface_vtbl *v3; // eax
  Scaleform::Render::HAL_vtbl *v4; // edx

  v3 = this->Scaleform::Render::RenderQueueItem::Interface::__vftable;
  v4 = qp->pHAL->__vftable;
  if ( v3 )
    ((void (__stdcall *)(Scaleform::Render::RenderQueueItem::Interface_vtbl *))v4->PushUserData)(v3);
  else
    ((void (*)(void))v4->PopUserData)();
}
