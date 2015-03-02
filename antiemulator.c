#include <sys/system_properties.h>

const char *emu_hardware[] = {
  "goldfish",
  NULL
};

const char *emu_brand[] = {
  "generic",
  NULL
};

bool is_emulator(){
  int index = 0;
  char property[512] = {0};

  /* check hardware */
  index = 0;
  property[0] = '\0';
  __system_property_get("ro.hardware", property);
  while(emu_hardware[index]){
    if (!strcmp(emu_hardware[index], property)){
      return true; /* is emulator*/
    }
    index++;
  }

  /* check brand */
  index = 0;
  property[0] = '\0';
  __system_property_get("ro.product.brand", property);
  while(emu_brand[index]){
    if (!strcmp(emu_hardware[index], property)){
      return true; /* is emulator*/
    }
    index++;
  }

  return false; /* no emulator*/
}
