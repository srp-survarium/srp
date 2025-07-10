void __cdecl EC_GROUP_set_point_conversion_form(ec_group_st *group, point_conversion_form_t form)
{
  group->asn1_form = form;
}
