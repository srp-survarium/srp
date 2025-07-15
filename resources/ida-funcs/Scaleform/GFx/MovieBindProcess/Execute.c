void __thiscall Scaleform::GFx::MovieBindProcess::Execute(Scaleform::GFx::MovieBindProcess *this)
{
  while ( Scaleform::GFx::MovieBindProcess::BindNextFrame(this) == BS_InProgress )
    ;
}
