point_conversion_form_t __cdecl EC_GROUP_get_point_conversion_form(const ec_group_st *group)
{
  return group->asn1_form;
}
