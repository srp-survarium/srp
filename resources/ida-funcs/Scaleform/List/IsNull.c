bool __thiscall Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify>::IsNull(
        Scaleform::List<Scaleform::Render::HALNotify,Scaleform::Render::HALNotify> *this,
        const Scaleform::Render::HALNotify *p)
{
  const Scaleform::Render::HALNotify *v2; // eax

  if ( this )
    v2 = (const Scaleform::Render::HALNotify *)&this[-1].Root.4;
  else
    v2 = 0;
  return p == v2;
}
