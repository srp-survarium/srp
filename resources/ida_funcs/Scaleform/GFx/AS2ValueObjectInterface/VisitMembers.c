void __thiscall Scaleform::GFx::AS2ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        bool isdobj)
{
  Scaleform::GFx::Value_AS2ObjectData o; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2ValueObjectInterface::VisitMembers::__l2::VisitorProxy visitorProxy; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&o, this, pdata, isdobj);
  visitorProxy.pMovieRoot = o.pRoot;
  visitorProxy.pEnv = o.pEnv;
  visitorProxy.pVisitor = visitor;
  visitorProxy.__vftable = (Scaleform::GFx::AS2ValueObjectInterface::VisitMembers::__l2::VisitorProxy_vtbl *)&`Scaleform::GFx::AS2ValueObjectInterface::VisitMembers'::`2'::VisitorProxy::`vftable';
  o.pObject->VisitMembers(o.pObject, &o.pEnv->StringContext, &visitorProxy, 3u, 0);
}
