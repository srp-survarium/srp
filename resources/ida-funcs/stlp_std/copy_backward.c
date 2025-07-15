survarium::animations_registry::animations_tuple *__usercall stlp_std::copy_backward<survarium::animations_registry::animations_tuple *,survarium::animations_registry::animations_tuple *>@<eax>(
        survarium::animations_registry::animations_tuple *__result@<eax>,
        survarium::animations_registry::animations_tuple *__first,
        survarium::animations_registry::animations_tuple *__last)
{
  survarium::animations_registry::animations_tuple *v3; // esi
  int v4; // ecx
  int v5; // edi
  int v6; // ebx

  v3 = __result;
  v4 = 12;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    v6 = (char *)__last - (char *)__result;
    do
    {
      --v3;
      survarium::animations_registry::animations_tuple::operator=(
        (survarium::animations_registry::animations_tuple *)v4,
        &v3->first_view,
        (survarium::animations_registry::animations_tuple *)((char *)v3 + v6));
      --v5;
    }
    while ( v5 > 0 );
  }
  return v3;
}
