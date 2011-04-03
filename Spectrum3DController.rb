# Spectrum3DController.rb
# AiffPlayer
#
# Created by koji on 11/03/10.
# Copyright 2011 __MyCompanyName__. All rights reserved.

class Spectrum3DWindowController < NSWindowController
	attr_accessor :view
	attr_accessor :aiff
	def awakeFromNib
		
	end 
	
	def init
		super.initWithWindowNibName("Spectrum3D")
		NSLog "#{self.class} initialized"
		@aiff = nil
		self
	end
	
	def setAiff(aiff)
		@aiff = aiff
		@view.aiff = @aiff
	end
	
	def windowWillLoad()

	end
	
	def windowDidLoad()	
		puts "windowDidLoad"
		#self.window.delegate = self
		
		#we do set processor 
		#@view.setProcessor(@processor)
	end
	
	def close()
		puts "Spectrum3D now closed"
		self.window.performClose nil
		
	end
	
	def windowShouldClose(sender)
		true
	end
	
end
