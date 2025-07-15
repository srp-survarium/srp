void __cdecl Scaleform::GFx::AS3::ForEachChild_GC_Internal(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::Value *v,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *),
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *owner)
{
  unsigned int v4; // eax

  v4 = v->Flags & 0x1F;
  switch ( v4 )
  {
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v->value.VS._1.VInt )
        op(prcc, v4 - 11 <= 4 ? (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v->value : 0, owner);
      break;
    case 0x10u:
    case 0x11u:
      if ( v->value.VS._2.VObj )
        op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v->value.VS._2.VObj, owner);
      break;
    default:
      return;
  }
}
