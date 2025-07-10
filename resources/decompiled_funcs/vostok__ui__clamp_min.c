void __usercall vostok::ui::clamp_min(float *val@<eax>)
{
  if ( *val < 0.0 )
    *val = 0.0;
}
