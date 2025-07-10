Scaleform::GFx::AMP::SocketInterface *__thiscall Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl>::Create(
        Scaleform::GFx::AMP::DefaultSocketFactory<Scaleform::GFx::AMP::GFxSocketImpl> *this)
{
  Scaleform::GFx::AMP::SocketInterface *result; // eax

  result = (Scaleform::GFx::AMP::SocketInterface *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     36,
                                                     0);
  if ( !result )
    return 0;
  result->__vftable = (Scaleform::GFx::AMP::SocketInterface_vtbl *)&Scaleform::GFx::AMP::GFxSocketImpl::`vftable';
  result[5].__vftable = (Scaleform::GFx::AMP::SocketInterface_vtbl *)-1;
  result[6].__vftable = (Scaleform::GFx::AMP::SocketInterface_vtbl *)-1;
  result[7].__vftable = 0;
  result[8].__vftable = 0;
  return result;
}
