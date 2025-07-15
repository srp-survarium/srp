int __usercall survarium::get_body_part_id_by_name@<eax>(
        const char *name@<esi>,
        const vostok::math::float3 *bullet_pos)
{
  if ( vostok::strings::compare(name, "front") )
  {
    if ( vostok::strings::compare(name, "back") )
    {
      if ( vostok::strings::compare(name, "brain") && vostok::strings::compare(name, "face") )
      {
        if ( vostok::strings::compare(name, "right_leg")
          && vostok::strings::compare(name, "right_foot")
          && vostok::strings::compare(name, "right_hip") )
        {
          if ( vostok::strings::compare(name, "left_leg")
            && vostok::strings::compare(name, "left_foot")
            && vostok::strings::compare(name, "left_hip") )
          {
            if ( vostok::strings::compare(name, "right_arm")
              && vostok::strings::compare(name, "right_hand")
              && vostok::strings::compare(name, "right_forearm") )
            {
              if ( vostok::strings::compare(name, "left_arm")
                && vostok::strings::compare(name, "left_hand")
                && vostok::strings::compare(name, "left_forearm") )
              {
                return 8;
              }
              else
              {
                return 2;
              }
            }
            else
            {
              return 3;
            }
          }
          else
          {
            return 6;
          }
        }
        else
        {
          return 7;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 1;
    }
  }
  else if ( bullet_pos->x <= 0.0 )
  {
    return 4;
  }
  else
  {
    return 5;
  }
}
