char __usercall Scaleform::GFx::AS2::AsBroadcaster::Initialize@<al>(
        unsigned __int8 *a1@<ebx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface *pobj)
{
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+4h] [ebp-4h]

  if ( pobj )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(a1, a2, pobj, psc, GAS_AsBcFunctionTable, 1u, v5);
  return Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance((int)psc, (int)pobj, psc, pobj, v5, v6);
}
