vostok::fixed_string<128> *__usercall vostok::animation::get_locator_format_string@<eax>(
        vostok::render::render_model_instance *item_model@<esi>,
        const vostok::animation::fingers_to_weapon_corrector::hands_enum hand@<eax>,
        const char *(*format_strings)[2][3],
        const unsigned int locator_set_id,
        const bool first_person_view)
{
  vostok::fixed_string<128> **v5; // ebx
  const char *v6; // eax
  vostok::fixed_string<128> **v7; // edi
  const char *v9; // [esp+8h] [ebp-17Ch] BYREF
  const char *v10; // [esp+94h] [ebp-F0h] BYREF
  _BYTE v11[96]; // [esp+120h] [ebp-64h] BYREF
  __int16 v12; // [esp+180h] [ebp-4h]
  char *format; // [esp+18Ch] [ebp+8h]

  v5 = (vostok::fixed_string<128> **)format_strings;
  v6 = s_arm_fingers_phalanges[hand][15];
  v12 = -1;
  v7 = (vostok::fixed_string<128> **)((char *)*format_strings + 4 * locator_set_id);
  format = (char *)v6;
  vostok::fixed_string<128>::createf(&v10, *v7, v6);
  if ( item_model->get_locator(item_model, v10, (vostok::render::model_locator_item *)v11)
    && (first_person_view
     || (v5 += locator_set_id + 3,
         vostok::fixed_string<128>::createf(&v9, *v5, format),
         !item_model->get_locator(item_model, v9, (vostok::render::model_locator_item *)v11))) )
  {
    return *v7;
  }
  else
  {
    return *v5;
  }
}
