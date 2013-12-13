<?php

/**
 * settings form's callback form form API
 *
 * @return void
 * @author Giorgi Jibladze
 */
function ipay_settings_form() {
	$form             = array();
	$form['username'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Username'),
	 '#default_value' => variable_get('ipay_username', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);

	$form['password'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Password'),
	 '#default_value' => variable_get('ipay_password', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);	

	return system_settings_form($form);
}
