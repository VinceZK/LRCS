CPP_SRCS += \
${addprefix $(ROOT)/Wrappers/Encoder/, \
DeltaEncoder.cpp \
Encoder.cpp \
IntEncoder.cpp \
StringEncoder.cpp \
UncompressedEncoder.cpp \
}

# Each subdirectory must supply rules for building sources it contributes
Encoder/%.o: $(ROOT)/Wrappers/Encoder/%.cpp
	@echo 'Building file: $<'
	@echo $(CC) $(CFLAGS) $(IFLAGS) -o $@ $< 
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ $< && \
	echo -n $(@:%.o=%.d) $(@D)/ > $(@:%.o=%.d) && \
	$(CC) $(RULEFLAGS) $(CFLAGS) $(IFLAGS) $< >> $(@:%.o=%.d)
	@echo 'Finished building: $<'
	@echo ' '